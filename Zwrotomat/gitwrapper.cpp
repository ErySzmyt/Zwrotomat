#include "gitwrapper.h"

#include <QFile>
#include <QDebug>
#include <QIODevice>
#include <QTextStream>
#include <QDir>
#include<stdio.h>
#include <stdlib.h>

GitWrapper::GitWrapper()
{

}

void GitWrapper::clone(QString HTTPS, QDir dir)
{
    // QString templates
    QString commandQString = "git clone "+HTTPS+" "+dir.path();
    qDebug()<<"QString command:"<<commandQString;
    // convert to required format
    std::string utf8_text = commandQString.toUtf8().constData();
    const char * command = utf8_text.c_str();
    qDebug()<<"converted command:"<<command;
    // execute command in cmd
    std::system(command);
    // delate pointers
    delete command;

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
