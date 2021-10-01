#include "customimport.h"
#include "ui_customimport.h"
#include "QtXml/QtXml"
#include "QFileDialog"
CustomImport::CustomImport(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CustomImport)
{
    ui->setupUi(this);
}

void CustomImport::importCommentsFromFile(QDir filePath)
{

    QDomDocument document;
    // read file
    QFile file(filePath.path());

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() << "nie mozna otworzyc pliku";
    }
    else{
        if(!document.setContent(&file)){
            qDebug() << "nie mozna zaladowac pliku do pamieci";
        }
        file.close();
    }
    QDomElement root = document.firstChildElement();
    QDomNodeList elements = root.elementsByTagName("comment");
    for (int i=0; i< elements.count();i++){
        QDomNode elemNode  = elements.at(i);
        if(elemNode.isElement()){
            QDomElement elem = elemNode.toElement();
            qDebug() << elem.attribute("comment");
            qDebug() << elem.attribute("code");
            qDebug() << elem.attribute("isPositive");
        }
    }
    /*
      std::ifstream xmlFile(filePath.path().toStdString());
      rapidxml::xml_document<> doc;
      static std::vector<char> buffer((std::istreambuf_iterator<char>(xmlFile)), std::istreambuf_iterator<char>( ));
      buffer.push_back('\0');
      doc.parse<0>(&buffer[0]);
      qDebug() << "1st node "<< doc.first_node()->name();
      rapidxml::xml_node<> *node = doc.first_node();

      for (rapidxml::xml_attribute<> *attr = node->first_attribute();
           attr; attr = attr->next_attribute())
      {
          qDebug() << "Node foobar has attribute " << attr->name() << " ";
          qDebug() << "with value " << attr->value() << "\n";
      }*/
}



void CustomImport::on_chooseButton_clicked()
{
    // select dir
    QString dir = QFileDialog::getOpenFileName(this,tr("Select XML file"));
    this->s_last_selectedDir = dir;
    ui->f_path->setText(dir);
}



CustomImport::~CustomImport()
{
    delete ui;
}

void CustomImport::on_export_2_clicked()
{
    // importuj
    this->importCommentsFromFile((this->s_last_selectedDir));
}
