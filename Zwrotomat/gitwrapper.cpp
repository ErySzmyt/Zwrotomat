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
    const char* w = cdTemplate.toStdString().c_str();
    std::system(w);
    QString commandTemplate = "git clone "+HTTPS;
    qDebug() << "test 2"+commandTemplate;
    const char* ch = commandTemplate.toStdString().c_str();
    std::system(ch);
    delete ch;
    delete w;

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
