#ifndef ROOTWINDOW_H
#define ROOTWINDOW_H

#include <QMainWindow>
#include "networkquerymanager.h"
#include "jsonparser.h"
#include "button.h"
#include "edit.h"
#include "radio.h"
#include "check.h"
#include <QGroupBox>
#include <QVBoxLayout>

namespace Ui {
class RootWindow;
}

namespace PageIndex{
namespace RootWindow {
enum PageIndex{Config = 0, TestProcess = 1, Administr };
}

}


class RootWindow : public QMainWindow
{
    Q_OBJECT
private:
    Ui::RootWindow *ui;

    QGridLayout *gLay;

    NetworkQueryManager *_netMan;
    JsonParser *_jParser;
    QVector<strQuestions> _questions;

    QGroupBox *_answerGroup;
    QVBoxLayout *_answersLay;

    selectedAnswersRadioMap _selRadioAnss;
    selectedAnswersCheckMap _selCheckAnss;
    enteredAns _entAnss;
    QList<QWidget*> _wgts;



    void createAnswers(const int questionNum, const QString &type, QVector<strAnswers> &answers);
    void createTextAnswers(QVector<strAnswers> &answers, int questionNum);
    void createCheckAnswers(QVector<strAnswers> &answers, int questionNum);
    void createRadioAnswers(QVector<strAnswers> &answers, int questionNum);
    void validateAnswers();
public:
    explicit RootWindow(QWidget *parent = 0);
    ~RootWindow();

    void connectSignals();
public slots:

private slots:
    void answerRadioSelected(int qNum, int ansNum);
    void answerCheckSelected(int qNum, int ansNum);
    void ansEntered(int qNum, const QString &text);

    // void on_PButton_Start_BeginTest_clicked();
    void setProfs(IdTitleMap profList);
    void setLessonsList(IdTitleMap lessonsList);
    void setThemesList( IdTitleMap themeList );
    void setMaxQuestionsCount(qint64 maxCount);
    //void setCourses(IdTitleMap coursesList);
    void questionSelected(int number);
    void on_ComboBox_Config_Profession_currentIndexChanged(int index);
    void on_ComboBox_Config_Lessons_currentIndexChanged(int index);
    void on_ComboBox_Config_Theme_currentIndexChanged(int index);
    void on_PButton_Config_Begin_clicked();
    void setQuestions(QVector<strQuestions> &questions);

    void on_pushButton_clicked();
};

#endif // ROOTWINDOW_H
