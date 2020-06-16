#include "filewrite.h"

FileWrite::FileWrite() {}

FileWrite::FileWrite(const QString& dir) {
    this->dir = dir;
}

bool FileWrite::SaveData(const QString& dir, const QString& str){
    QFile mFile(this->dir + dir);
    mFile.open(QIODevice::WriteOnly);
    if (!mFile.isOpen())
        return 1;
    QTextStream fstream(&mFile);
    fstream << str;
    mFile.close();
    return 0;
}

bool FileWrite::ReplaceFile(const QString& source, const QString& str){
    QFile::setPermissions(this->dir + str, QFile::ReadOwner | QFile::WriteOwner);
    QFile::remove(this->dir + str);
    QFile::copy(source, this->dir + str);
    return 0;
}
