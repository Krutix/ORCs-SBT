#ifndef FILEWRITE_H
#define FILEWRITE_H

#include <QDir>
#include <QTextStream>
#include <QFile>
#include <QString>
#include <QFileDialog>
#include <QDebug>

class FileControl
{
public:
    FileControl();

    static bool SaveData(const QString& dir, const QString& str);
    static bool SaveImgPNG(const QString& sourcedir, const QString& finaldir);
    static bool ReplaceFile(const QString& sourcedir, const QString& finaldir);
    static QString ReadFile(const QString& dir);
    static QString GetPath(QWidget* obj, const QString& name, const QString& str);
private:
};

#endif // FILEWRITE_H
