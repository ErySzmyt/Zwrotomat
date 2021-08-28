#include "gitwrapper.h"

#include <QString>
#include <QDebug>
#include <QFile>
#include "gitwrapper.h"

void GitWrapper::readGitCredential()
{
   QString userName = qgetenv("USERNAME");
   QString gitConfigPath = "C:\\Users\\"+userName+"\\.gitconfig";
   QFile fileExist(gitConfigPath);

   qDebug() <<"czy istnmieje" <<fileExist.exists();

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


void clone(QString HTTPS){
    //to do
}


GitWrapper::GitWrapper()
{


}

void GitWrapper::setEmail(QString email)
{
    this->m_email = email;

}

void GitWrapper::setUserName(QString userName)
{
    this->m_username = userName;

}
