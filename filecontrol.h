#ifndef FILEWRITE_H
#define FILEWRITE_H

#include <QDir>
#include <QTextStream>
#include <QFile>
#include <QString>
#include <QFileDialog>
#include <QDebug>

namespace FileControl {

    bool SaveData(const QString& dir, const QString& str);
    bool SaveImgPNG(const QString& sourcedir, const QString& finaldir);
    bool DeleteImgPNG(const QString& dir);
    bool ReplaceFile(const QString& sourcedir, const QString& finaldir);
    QString ReadFile(const QString& dir);
    QString GetPath(QWidget* obj, const QString& name, const QString& str);

}

#endif // FILEWRITE_H
