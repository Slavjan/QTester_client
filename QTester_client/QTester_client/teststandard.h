#pragma once
#ifndef TESTSTANDARD_H
#define TESTSTANDARD_H

#include <QString>
#include <QVector>
#include <QLocale>
#include "lesson.h"



class TestStandard
{
private:
	QString _id;
	QString _name;
	QVector<Lesson> _lesson; // \todo TODO: придумать что с этим делать	  
	// может быть Map<предмет(название или id), колво вопросов по нему>
	int questionsCount;
	QMap<int, int> rang;

public:
	TestStandard();

	static QString getId();
	static QString getName();
};
#endif