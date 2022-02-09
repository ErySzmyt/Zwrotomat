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
    this->readGitCredential();
}

/**
 * @brief GitWrapper::clone action to clone given repository
 * @param HTTPS link to repository
 * @param dir output directory
 * @return output directory afther clonning
 */
QDir GitWrapper::clone(QString HTTPS, QDir dir)
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
    //delete command;

    return dir;
}

/**
 * @brief GitWrapper::setEmail changing default git config's email
 * @param email new email to set
 */
void GitWrapper::setEmail(QString email)
{
    this->m_email = email;
}

/**
 * @brief GitWrapper::setUserName changing default git config's username
 * @param userName username to set
 */
void GitWrapper::setUserName(QString userName)
{
    this->m_username = userName;
}

/**
 * @brief GitWrapper::readGitCredential reading github credential if avilable
 */
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
            //qDebug() << "Git User Name" << line.split('=')[1];
            this->m_username = line.split('=')[1];
        }
        if (line.startsWith("\temail") ){
            //qDebug() << "Git email" << line.split('=')[1];
            this->m_email = line.split('=')[1];
        }
    }

    qDebug() << "gitConfigPath" << gitConfigPath;
}

/**
 * @brief GitWrapper::getUsername getter for username
 * @return git username
 */
QString GitWrapper::getUsername()
{
    return this->m_username;
}

/**
 * @brief GitWrapper::getEmail getter for git's email
 * @return git email
 */
QString GitWrapper::getEmail()
{
    return this->m_email;
}
