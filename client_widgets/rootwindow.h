#ifndef ROOTWINDOW_H
#define ROOTWINDOW_H

#include <QMainWindow>
#include "networkquerymanager.h"
#include "jsonparser.h"
#include "button.h"
#include <QGroupBox>
#include <QVBoxLayout>
#include <QTreeWidget>


#include <QStringListModel>
#include <QStandardItemModel>

#include "radio.h"
#include "check.h"
#include "edit.h"

namespace Ui {
class RootWindow;
}

namespace PageIndex{
    namespace RootWindow {
        enum PageIndex{Config = 0, TestProcess = 1, Administr };
    }
}

typedef QMap<int, QString> enteredAns;
typedef QVector<QTreeWidgetItem*> TreeItems;

class RootWindow : public QMainWindow
{
    Q_OBJECT
private:
    Ui::RootWindow *ui;

    NetworkQueryManager *_netMan;
    JsonParser *_jParser;
    QVector<strQuestions> _questions;

    QGroupBox *_answerGroup;
    QVBoxLayout *_answersLay;

    selectedAnswersRadioMap _selRadioAnss;
    selectedAnswersCheckMap _selCheckAnss;
    enteredAns  _entAnss;

    TreeItems topItems;
    QTreeWidgetItem *_selected;

    void createAnswers(const int questionNum, const QString &type, QVector<strAnswers> &answers);
    void createRadioAnswers(QVector<strAnswers> &answers, int questionNum);
    void createCheckAnswers(QVector<strAnswers> &answers, int questionNum);
    void createTextAnswers(QVector<strAnswers> &answers, int questionNum);
//    QStandardItem createTableModelIndex(const QString &indexName, const int row,
//                                        const QStandardItem &chiledItem = QModelIndex());
//    QStandardItem createProfTreeModel();

    void createTabelsTreeModel();
    TreeItems addTreeChilds(QTreeWidget *twg,
                            const QStringList &itemsNames,
                            const QStringList &whatsThis,
<<<<<<< HEAD
                            const QVector<int> whatThisCol);
    TreeItems addTreeChilds(QTreeWidgetItem *twgi,
                            const QStringList &itemsNames ,
                            const QStringList &whatsThis,
                            const QVector<int> whatThisCol);
    TreeItems addProfsTreeChilds(QTreeWidget *viewport,
                               const QStringList &itemsNames,
                               const QStringList &whatsThis);
    TreeItems addProfsTreeChilds(QTreeWidgetItem *parent,
                               const QStringList &itemsNames,
                               const QStringList &whatsThis);
    TreeItems addLessonsTreeChilds(QTreeWidget *viewport,
                                   const QStringList &itemsNames,
                                   const QStringList &whatsThis);
    TreeItems addLessonsTreeChilds(QTreeWidgetItem *parent,
                                   const QStringList &itemsNames,
                                   const QStringList &whatsThis);
    TreeItems addThemesTreeChilds(QTreeWidgetItem *parent,
                                  const QStringList &itemsNames,
                                  const QStringList &whatsThis);
    TreeItems addThemesTreeChilds(QTreeWidget *viewport,
                                  const QStringList &itemsNames,
                                  const QStringList &whatsThis);
=======
                            const int whatThisCol = 0);
    TreeItems addTreeChilds(QTreeWidgetItem *twgi,
                            const QStringList &itemsNames ,
                            const QStringList &whatsThis,
                            const int whatThisCol = 0);
    TreeItems addProfsTreeChilds(QTreeWidget *viewport,
                               const QStringList &itemsNames,
                               const QStringList &whatsThis,
                               const int whatThisCol = 0);
    TreeItems addProfsTreeChilds(QTreeWidgetItem *parent,
                               const QStringList &itemsNames,
                               const QStringList &whatsThis,
                                const int whatThisCol = 0);
    TreeItems addLessonsTreeChilds(QTreeWidget *viewport, const QStringList &itemsNames, const QStringList &whatsThis, const int whatThisCol);
    TreeItems addLessonsTreeChilds(QTreeWidgetItem *parent, const QStringList &itemsNames, const QStringList &whatsThis, const int whatThisCol);
    TreeItems addThemesTreeChilds(QTreeWidgetItem *parent, const QStringList &itemsNames, const QStringList &whatsThis, const int whatThisCol);
    TreeItems addThemesTreeChilds(QTreeWidget *viewport, const QStringList &itemsNames, const QStringList &whatsThis, const int whatThisCol);
>>>>>>> 7d752a6e2ca132eb4560e44871073a1621247025
public:
    explicit RootWindow(QWidget *parent = 0);
    ~RootWindow();

    void connectSignals();
public slots:

private slots:

    // void on_PButton_Start_BeginTest_clicked();
    void setProfs(IdTitleMap profList);
    void setLessonsList(IdTitleMap lessonsList);
    void setThemesList( IdTitleMap themeList );
    void setMaxQuestionsCount(qint64 maxCount);
<<<<<<< HEAD
    void setProfsTree(IdTitleMap profTree, QTreeWidgetItem *selectedItem);
=======
  //  void setProfsTree();
>>>>>>> 7d752a6e2ca132eb4560e44871073a1621247025

    //void setCourses(IdTitleMap coursesList);
    void questionSelected(int number);
    void on_ComboBox_Config_Profession_currentIndexChanged(int index);
    void on_ComboBox_Config_Lessons_currentIndexChanged(int index);
    void on_ComboBox_Config_Theme_currentIndexChanged(int index);
    void on_PButton_Config_Begin_clicked();
    void setQuestions(QVector<strQuestions> &questions);

    void answerRadioSelected(int qNum, int ansNum);
    void answerCheckSelected(int qNum, int ansNum);
    void ansEntered(int qNum, const QString &text);
    void on_pushButton_4_clicked();
    void on_PButton_Config_Back_clicked();
    void itemWhats(QTreeWidgetItem *item, int column);
    void on_TreeWidget_Admin_QuestionsBase_itemChanged(QTreeWidgetItem *item, int column);
};

#endif // ROOTWINDOW_H
