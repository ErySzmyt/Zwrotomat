#include "gitwrapper.h"

#include <QFile>
#include <QDebug>
#include <QIODevice>
#include <QTextStream>
#include <QDir>
#include  <stdlib.h>

GitWrapper::GitWrapper()
{

}

void GitWrapper::clone(QString HTTPS, QDir dir)
{
    QString cdTemplate = "cd "+dir.path();
    qDebug()<<"test"<< cdTemplate;
    // convert
    std::string utf8_text = cdTemplate.toUtf8().constData();
    const char * c = utf8_text.c_str();
    //const char* w = cdTemplate.toStdString().c_str();
    qDebug()<< "test stringa 1:"<<c;
    std::system(c);
    QString commandTemplate = "git clone "+HTTPS;
    qDebug() << "test 2"+commandTemplate;
    std::string utf8_text2 = cdTemplate.toUtf8().constData();
    const char * c2 = utf8_text2.c_str();
    qDebug() <<"test stringa 2:"<<  c2;

    std::system(c2);
    delete[] c2;
    delete[] c;

}

void GitWrapper::setEmail(QString email)
{
    this->m_email = email;
}

void GitWrapper::setUserName(QString userName)
{
    this->m_username = userName;
}

void GitWrapper::readGitCredential()
{
    QString userName = qgetenv("USERNAME");
        QString gitConfigPath = "C:\\Users\\"+userName+"\\.gitconfig";
        QFile inputFile(gitConfigPath);

        inputFile.open(QIODevice::ReadOnly);
        if (!inputFile.isOpen())
            return;

        QTextStream stream(&inputFile);
        for (QString line = stream.readLine();
             !line.isNull();
             line = stream.readLine()) {

            if (line.startsWith("\tname")){
                qDebug() << "Git User Name" << line.split('=')[1];
                //this->m_username = line.split('=')[1];
            }
            if (line.startsWith("\temail") ){
                qDebug() << "Git email" << line.split('=')[1];
                //this->m_email = line.split('=')[1];
            }
        }

        qDebug() << gitConfigPath;
}

QString GitWrapper::getUsername()
{
    return this->m_username;
}

QString GitWrapper::getEmail()
{
    return this->m_email;
}
