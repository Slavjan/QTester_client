#pragma once

#include <QString>
#include <QVector>
#include <QLocale>
#include "Theme.h"

class Lesson
{
private:
	QString _title;
	QLocale::Language _lang;
	QVector<Theme> _themes;
public:
	Lesson(){};
	Lesson(const QString &title);

	QString getTitle() const;
	QLocale::Language getLang() const;
	QVector<Theme> getThemes() const;

	void setTitle(const QString &title);
	void setLang(const QLocale::Language &lang);
	void pushTheme(const Theme &theme);
};

