#include "filewrite.h"

FileWrite::FileWrite() {}

FileWrite::FileWrite(const QString& dir) {
    this->dir = dir;
}

bool FileWrite::SaveDataInDir(const QString& dir, const QString& str){
    QFile mFile(this->dir + dir);
    mFile.open(QIODevice::WriteOnly);
    if (!mFile.isOpen())
        return 1;
    QTextStream fstream(&mFile);
    fstream << str;
    mFile.close();
    return 0;
}

bool FileWrite::SaveImgToDir(const QString& sourcedir, const QString& finaldir){
    ReplaceFileInDir(sourcedir, finaldir + ".png");
    SaveDataInDir(finaldir + ".txt", sourcedir);
    return 0;
}

bool FileWrite::ReplaceFileInDir(const QString& sourcedir, const QString& finaldir){
    QFile::setPermissions(this->dir + finaldir, QFile::ReadOwner | QFile::WriteOwner);
    QFile::remove(this->dir + finaldir);
    QFile::copy(sourcedir, this->dir + finaldir);
    return 0;
}
