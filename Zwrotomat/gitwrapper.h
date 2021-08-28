#ifndef GITWRAPPER_H
#define GITWRAPPER_H

#include <QString>
class GitWrapper
{
public:
GitWrapper();
     void clone(QString HTTPS);
     void setEmail(QString email);
     void setUserName(QString userName);

    static  void readGitCredential();
    QString getUsername();
    QString getEmail();

private:
     QString m_username;
     QString m_email;



};

#endif // GITWRAPPER_H
