#ifndef APPLICATIONSETTINGS_H
#define APPLICATIONSETTINGS_H

#include <QObject>
#include "QSettings"
#include <QStringList>
#include <QPair>

class ApplicationSettings : public QObject
{
    Q_OBJECT
public:
    explicit ApplicationSettings(QObject *parent = nullptr);

    void setHeroes(QPair<QStringList, QStringList> heroes);
    QPair<QStringList, QStringList> getHeroes();

signals:
    void heroesChange(QPair<QStringList, QStringList>);

private:
    QSettings settings;
    QPair<QStringList, QStringList> heroes;
};

#endif // APPLICATIONSETTINGS_H
