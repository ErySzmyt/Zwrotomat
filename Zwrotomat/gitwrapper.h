#ifndef GITWRAPPER_H
#define GITWRAPPER_H

#include <QString>
class GitWrapper
{
private:
     QString m_username;
     QString m_email;
public:
    GitWrapper();

    void clone(QString HTTPS);
    void setEmail(QString email);
    void setUserName(QString userName);

    void readGitCredential();
    QString getUsername();
    QString getEmail();
};

#endif // GITWRAPPER_H
