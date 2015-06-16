#include "rootwindow.h"
#include "ui_rootwindow.h"
#include "autorisationdialog.h"

#include <QDir>
#include <QCheckBox>
#include <QRadioButton>
#include <QLineEdit>

namespace QuestionTypes {
    const QString RADIO = "RADIO";
    const QString CHECK = "CHECK";
    const QString TEXT  = "TEXT ";
}


void RootWindow::connectSignals()
{
    connect( _netMan->getClient(), SIGNAL(dataRecieved(QString)),
             _jParser, SLOT(responseSlot(QString)) );
    //pull requests
    // profList
    connect( _jParser, SIGNAL(takeProfs(IdTitleMap)),
             this, SLOT(setProfs(IdTitleMap)));
}

void RootWindow::setProfs(IdTitleMap profList)
{
    ui->ComboBox_Config_Profession->clear();
    ui->ComboBox_Config_Profession->blockSignals( true );
    for (auto it = profList.begin(); it != profList.end(); ++it)
    {
        ui->ComboBox_Config_Profession->addItem(it.value(), it.key());
    }
    ui->ComboBox_Config_Profession->blockSignals( false );
}

RootWindow::RootWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RootWindow)
{
    ui->setupUi(this);
    _jParser = JsonParser::instance(this);
    _netMan = new NetworkQueryManager("127.0.0.1", 3434);

    this->hide();

    connectSignals();
    _netMan->sendPullRequestProfList();

    AutorisationDialog _AuthForm(_netMan, _jParser);
    _AuthForm.exec();
}

RootWindow::~RootWindow()
{
    delete ui;
}

void RootWindow::on_ComboBox_Config_Profession_currentIndexChanged(int index)
{
    //  QString profId = ui->ComboBox_Config_Profession->itemData(index).toString();
    QString profId = ui->ComboBox_Config_Profession->currentData().toString();
    qDebug() << "profId >" << profId;
    _netMan->sendPullRequestLessonsList(profId);
    connect(_jParser, SIGNAL(takeLessons(IdTitleMap)),
            this, SLOT(setLessonsList(IdTitleMap)));
}

void RootWindow::setLessonsList(IdTitleMap lessonsList)
{
    ui->ComboBox_Config_Lessons->clear();
    ui->ComboBox_Config_Lessons->blockSignals( true );
    for (auto it = lessonsList.begin(); it != lessonsList.end(); ++it)
    {
        ui->ComboBox_Config_Lessons->addItem(it.value(), it.key());
        qDebug() << "[RootWindow::setLessonsList] it.val: " << it.value() << " it.key:" << it.key()
            << ui->ComboBox_Config_Lessons->currentData().toString();
        
    }
    ui->ComboBox_Config_Lessons->blockSignals( false );
}

void RootWindow::setThemesList( IdTitleMap themeList )
{
   ui->ComboBox_Config_Theme->clear();
    ui->ComboBox_Config_Theme->blockSignals( true );
    for (auto it = themeList.begin(); it != themeList.end(); ++it)
    {
        ui->ComboBox_Config_Theme->addItem(it.value(), it.key());
        qDebug() << "[RootWindow::setThemesList] it.val: " << it.value() << " it.key:" << it.key();
    }
    ui->ComboBox_Config_Theme->blockSignals( false );
}

void RootWindow::setMaxQuestionsCount(qint64 maxCount)
{
   // ui->HorizontalSlider_Config_QuestionsCount->setMinimum(/*maxCount>5 ? 5: 0*/ 100);
}

void RootWindow::setQuestions(QVector<strQuestions> questions)
{
    _questions = questions;
    QString profession = ui->ComboBox_Config_Profession->currentText(),
        lesson = ui->ComboBox_Config_Lessons->currentText(),
        theme = ui->ComboBox_Config_Theme->currentText(),
        questionText = questions.first().text,
        questionType = questions.first().type;


    for (int j = 0; j < questions.count(); ++j)
    {
        int questionId = questions.at(j).id;
        Button *btn = new Button( QString::number( j+1 ), questionId );
        ui->GLay_Tester_Questions->layout()->addWidget(btn);
//        btn->show();
        connect( btn, SIGNAL( selected(int)),
                 this, SLOT(quesionSelected(int)) );
    }

    /// \todo generate answers for firs question
    ui->Label_Tester_Profession->setText( profession );
    ui->Label_Tester_Lesson->setText( lesson );
    ui->Label_Tester_Theme->setText( theme );
    ui->Label_Tester_Question->setText( questionText );
    if (questionType == QuestionTypes::RADIO)
    {
        QRadioButton *radio;
        for (int i = 0; i < 5; ++i)
        {
            radio = new QRadioButton;
            radio->setText(questions.first().answers.at(i).text);
            ui->VLay_Tester_Answers->addWidget( radio );
        }

    }
    else if(questionType == QuestionTypes::CHECK )
    {
        QCheckBox *check;
        for (int i = 0; i < 5; ++i)
        {
            check = new QCheckBox;
            check->setText(questions.first().answers.at(i).text);
            ui->VLay_Tester_Answers->addWidget( check );
        }
    }
    else if (questionType == QuestionTypes::TEXT)
    {
        QLineEdit *edit = new QLineEdit;
        ui->VLay_Tester_Answers->addWidget( edit );
    }

}

void RootWindow::questionSelected(int id)
{

}



void RootWindow::on_ComboBox_Config_Lessons_currentIndexChanged(int index)
{
    qDebug() << ui->ComboBox_Config_Lessons->currentData().toInt();
    QString lessonsId = ui->ComboBox_Config_Lessons->currentData().toString();
    qDebug() << "lessonsId" << lessonsId;
    _netMan->sendPullRequestThemesList(lessonsId);
    connect(_jParser, SIGNAL(takeThemes(IdTitleMap)),
            this, SLOT(setThemesList(IdTitleMap)));
}

void RootWindow::on_ComboBox_Config_Theme_currentIndexChanged(int index)
{
    // нужно запросить максимальное количество вопросов в базе данных
    QString themeId = ui->ComboBox_Config_Theme->currentData().toString();
    qDebug() << "themeId" << themeId;
    //_netMan->sendPullRequestQuestionsCount(themeId);         // TODO : change that
    connect(_jParser, SIGNAL(takeQuestionsCount(qint64)),
            this, SLOT(setMaxQuestionsCount(qint64)));
}

void RootWindow::on_PButton_Config_Begin_clicked()
{
    QString themeId = ui->ComboBox_Config_Theme->currentData().toString();
    qint64 questionsCount = ui->SBox_Config_needQCount->value(),
            answersCount = 5;
    _netMan->sendPullRequestQuestions(themeId, questionsCount, answersCount);
    connect(_jParser, SIGNAL(takeQuestions(QVector<strQuestions>)),
            this, SLOT(setQuestions(QVector<strQuestions>)));
    ui->stackedWidget->setCurrentIndex(PageIndex::RootWindow::TestProcess);
}
