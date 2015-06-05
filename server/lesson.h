#pragma once
#ifndef LESSON_H
#define LESSON_H

#include <QString>
#include <QVector>
#include <QLocale>
#include "theme.h"

class Lesson
{
private:
    QString _id;
    QString _name;
    QString _title;
    QLocale::Language _lang;
    int course;
    QVector<Theme> _themes;
    QVector<QString> _themesIds;


    Theme selectTheme( const QString &themeId, 
                       const SQLMgr &sqlManager, 
                       const qint64 questionsCount,
                       const int answersCount )const;

public:
    Lesson(){};
    Lesson(const QString &name);

    QString getId()const;
    QString getName()const;
    QString getTitle() const;
    QLocale::Language getLang() const;
    QVector<Theme> getThemes() const;                

    void setId( QString &id );
    void setName( QString &name );
	void setTitle(const QString &title);
	void setLang(const QLocale::Language &lang);
    void pushTheme(const Theme &theme);

	void selectThemesFromDataBase(const SQLMgr &sqlManager, 
		                          const QStringList &themeIds,
                                  const qint64 questionsCount,
                                  const int answersCount);
    static IdTitleMap getLessonsList( const SQLMgr &sqlManager, const QString &profId );
    void print()const; 
};

namespace Table
{
	namespace Lesson
	{
		const QString TABLE_NAME = "Lessons";

		namespace Fields
		{
			const QString LESSON_ID = "lesson_id";
			const QString NAME = "name";
			const QString TITLE = "title";
            const QString LANGUAGE = "localization";
            const QString COURSE = "course";
			const QString PROFESTION_ID = "profestion_id";
		}
	}
}
#endif