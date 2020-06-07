#include "updateextdata.h"

UpdateExtData::UpdateExtData()
{
    dir = new QDir(QApplication::applicationDirPath());
    qDebug() << "Путь запускаемого файла: " << QApplication::applicationDirPath();
    dir->mkdir("Current Match");
}

UpdateExtData::~UpdateExtData()
{
    delete dir;
}

void UpdateExtData::UpdateCurrentMap(const QString& str){
    qDebug() << "Update current map data: " << str;
    QFile mFile(dir->path() + "/Current Match/Map.txt");
    mFile.open(QIODevice::WriteOnly);
    QTextStream fstream(&mFile);
    fstream << str;
    mFile.close();
}

void UpdateExtData::UpdateNameT1 (const QString& str){
    qDebug() << "Update team 1 name data: " << str;
    QFile mFile(dir->path() + "/Current Match/Team1_Name.txt");
    mFile.open(QIODevice::WriteOnly);
    QTextStream fstream(&mFile);
    fstream << str;
    mFile.close();
}

void UpdateExtData::UpdateNameT2 (const QString& str){
    qDebug() << "Update team 2 name data: " << str;
    QFile mFile(dir->path() + "/Current Match/Team2_Name.txt");
    mFile.open(QIODevice::WriteOnly);
    QTextStream fstream(&mFile);
    fstream << str;
    mFile.close();
}

void UpdateExtData::UpdateShortNameT1(const QString& str){
    qDebug() << "Update team 1 short name data: " << str;
    QFile mFile(dir->path() + "/Current Match/Team1_ShortName.txt");
    mFile.open(QIODevice::WriteOnly);
    QTextStream fstream(&mFile);
    fstream << str;
    mFile.close();
}

void UpdateExtData::UpdateShortNameT2(const QString& str){
    qDebug() << "Update team 2 short name data: " << str;
    QFile mFile(dir->path() + "/Current Match/Team2_ShortName.txt");
    mFile.open(QIODevice::WriteOnly);
    QTextStream fstream(&mFile);
    fstream << str;
    mFile.close();
}

void UpdateExtData::UpdateCurrentScoreT1(const int& score){
    qDebug() << "Update team 1 score data: " << QString::number(score);
    QFile mFile(dir->path() + "/Current Match/Team1_Score.txt");
    mFile.open(QIODevice::WriteOnly);
    QTextStream fstream(&mFile);
    fstream << score;
    mFile.close();
}

void UpdateExtData::UpdateCurrentScoreT2(const int& score){
    qDebug() << "Update team 1 score data: " << QString::number(score);
    QFile mFile(dir->path() + "/Current Match/Team2_Score.txt");
    mFile.open(QIODevice::WriteOnly);
    QTextStream fstream(&mFile);
    fstream << score;
    mFile.close();
}
