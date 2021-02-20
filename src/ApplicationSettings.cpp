#include "ApplicationSettings.h"

ApplicationSettings::ApplicationSettings(QObject *parent) : QObject(parent)
{
    this->heroes = qMakePair(settings.value("heroes/hero_list").toStringList(),
                             settings.value("heroes/value").toStringList());
}

void ApplicationSettings::setHeroes(QPair<QStringList, QStringList> heroes)
{
    this->heroes = heroes;
    settings.setValue("heroes/hero_list", QVariant::fromValue(heroes.first));
    settings.setValue("heroes/value", QVariant::fromValue(heroes.second));
    emit heroesChange(heroes);
}

QPair<QStringList, QStringList> ApplicationSettings::getHeroes()
{
    return this->heroes;
}
