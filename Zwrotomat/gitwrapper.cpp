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
    QString pathToDir = dir.path();
    QString commandTemplate = "git clone "+HTTPS;
    // debug test templates in QString
    qDebug()<<"test QString 1"<< pathToDir;
    qDebug()<<"test QString 2"<< commandTemplate;
    // convert to required format
    // path
    std::string utf8_text = pathToDir.toUtf8().constData();
    const char * path = utf8_text.c_str();
    qDebug()<<"converted path:"<<path;
    // clone command
    std::string utf8_text2 = commandTemplate.toUtf8().constData();
    const char * command = utf8_text2.c_str();
    qDebug()<<"converted command:"<<command;
    // execute command in cmd
        // change directiory with chdir or sth
    //std::system(command);
    // delate pointers
    delete[] path;
    delete[] command;

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
