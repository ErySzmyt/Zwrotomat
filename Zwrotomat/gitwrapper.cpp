#include "gitwrapper.h"

#include <QString>
#include <QDebug>
#include "gitwrapper.h"

void GitWrapper::readGitCredential()
{
   QString userName = qgetenv("USERNAME");
   QString gitConfigPath = "C:\\Users\\"+userName+"\\.gitconfig";

   qDebug() << gitConfigPath;

}

GitWrapper::GitWrapper()
{




}
