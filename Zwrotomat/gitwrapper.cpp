#include "gitwrapper.h"

#include <QString>
#include <QDebug>
#include <QFile>
#include "gitwrapper.h"

void GitWrapper::readGitCredential()
{
   QString userName = qgetenv("USERNAME");
   QString gitConfigPath = "C:\\Users\\"+userName+"\\.gitconfig";
   QFile inputFile(gitConfigPath);
   //"\tname = Mateusz S"
   //"\temail = matesta383@student.polsl.pl"

   inputFile.open(QIODevice::ReadOnly);
   if (!inputFile.isOpen())
       return;

   QTextStream stream(&inputFile);
   for (QString line = stream.readLine();
        !line.isNull();
        line = stream.readLine()) {

       if ( line.startsWith("\tname")){
           qDebug()<< line;

       }
       if ( line.startsWith("\temail") ){
           qDebug()<< line;
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
