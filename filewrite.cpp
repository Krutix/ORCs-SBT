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
