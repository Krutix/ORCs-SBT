#ifndef FILEWRITE_H
#define FILEWRITE_H

#include <QDir>
#include <QTextStream>
#include <QFile>
#include <QString>

class FileWrite
{
public:
    FileWrite();
    FileWrite(const QString&);

    bool SaveDataInDir(const QString& dir, const QString& str);
    bool SaveImgToDir(const QString& sourcedir, const QString& finaldir);
    bool ReplaceFileInDir(const QString& sourcedir, const QString& finaldir);
private:
    QString dir = "";
};

#endif // FILEWRITE_H
