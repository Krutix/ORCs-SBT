#ifndef CASTOM_DATA_H
#define CASTOM_DATA_H

#include <QString>

struct Team 
{
    QString name;
	QString shortName;
	QString logoPath;
	int score;

	Team(const QString& name = "",
		const QString& sName = "",
		const QString& logo = "",
		const int& score = 0)
		: name(name), shortName(sName),
		logoPath(logo), score(score) {}
};

struct MutualMapInfo 
{
	QString currentMap;
	QString mutualInfo;

	MutualMapInfo(const QString& cMap = "None",
		const QString& mInfo = "")
		: currentMap(cMap), mutualInfo(mInfo) {}
};

struct CastTeam
{
	QString producer,
		observer[2],
		caster[2],
		host,
		analist[2];
	CastTeam(const QString& prod = "", const QString& obs1 = "",
		const QString& obs2 = "", const QString& cast1 = "", const QString& cast2 = "",
		const QString& host = "", const QString& an1 = "", const QString& an2 = "")
		: producer(prod), observer{ obs1, obs2 }, caster{ cast1, cast2 }, host(host), analist{ an1, an2 } {}
};

#endif