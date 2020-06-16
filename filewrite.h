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

    bool SaveData(const QString&, const QString&);
    bool ReplaceFile(const QString& dir, const QString& str);
private:
    QString dir = "";
};

#endif // FILEWRITE_H
