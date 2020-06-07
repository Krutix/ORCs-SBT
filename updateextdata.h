#ifndef UPDATEEXTDATA_H
#define UPDATEEXTDATA_H

#include <QApplication>
#include <QDir>
#include <QFileSystemModel>
#include <QFile>
#include <QDebug>

class UpdateExtData
{
public:
    UpdateExtData();
    ~UpdateExtData();

    void UpdateCurrentMap(const QString&);

    void UpdateNameT1 (const QString&);
    void UpdateNameT2 (const QString&);
    void UpdateShortNameT1(const QString&);
    void UpdateShortNameT2(const QString&);
    void UpdateCurrentScoreT1(const int&);
    void UpdateCurrentScoreT2(const int&);

private:
    QDir* dir = nullptr;
};

#endif // UPDATEEXTDATA_H
