#include "filecontrol.h"

FileControl::FileControl() {}

bool FileControl::SaveData(const QString& dir, const QString& str){
    QFile mFile(dir);
    mFile.open(QIODevice::WriteOnly);
    if (!mFile.isOpen())
        return false;
    QTextStream fstream(&mFile);
    fstream << str;
    mFile.close();
    return true;
}

bool FileControl::SaveImgPNG(const QString& sourcedir, const QString& finaldir){
    if (!QFile(sourcedir).exists())
        return false;
    ReplaceFile(sourcedir, finaldir + ".png");
    SaveData(finaldir + ".txt", sourcedir);
    return true;
}

bool FileControl::ReplaceFile(const QString& sourcedir, const QString& finaldir){
    if (!QFile(sourcedir).exists())
        return false;
    if (QFile(finaldir).exists()){
        QFile::setPermissions(finaldir, QFile::ReadOwner | QFile::WriteOwner);
        QFile::remove(finaldir);
    }
    QFile::copy(sourcedir, finaldir);
    return true;
}

QString FileControl::ReadFile(const QString& dir){
    QString tbh = "";
    if (QFile(dir).exists()){
        QFile file (dir);
        file.open(QIODevice::ReadOnly);
        tbh = file.readAll();
        file.close();
    }
    return tbh;
}

QString FileControl::GetPath(QWidget* obj, const QString& name, const QString& str){
    static QString lastDir = "";
    const QString filepath = QFileDialog::getOpenFileName(obj, name, lastDir, str);
    lastDir = filepath;
    qDebug() << lastDir;
    return filepath;
}
