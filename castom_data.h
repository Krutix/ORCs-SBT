#ifndef CASTOM_DATA_H
#define CASTOM_DATA_H

#include <QString>

struct Player 
{
	QString nickname = "";
	QString hero = "";
	QString socials = "";
};

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
	QString currentMap = "";
	QString mutualInfo = "";

	MutualMapInfo(const QString& cMap = "None",
		const QString& mInfo = "")
		: currentMap(cMap), mutualInfo(mInfo) {}
};

#endif