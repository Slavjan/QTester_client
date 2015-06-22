#include "rootwindow.h"
#include "ui_rootwindow.h"
#include "autorisationdialog.h"
#include "tilelayout.h"


#include <QDir>
#include <QCheckBox>
#include <QRadioButton>
#include <QLineEdit>
#include <QButtonGroup>
#include <QList>



namespace QuestionTypes
{
    const QString RADIO = "RADIO";
    const QString CHECK = "CHECK";
    const QString TEXT = "TEXT";
}

void RootWindow::connectSignals()
{
    connect( _netMan->getClient(), SIGNAL( dataRecieved( QString ) ),
             _jParser, SLOT( responseSlot( QString ) ) );
    //pull requests
    // profList
    connect( _jParser, SIGNAL( takeProfsList( IdTitleMap ) ),
             this, SLOT( setProfs( IdTitleMap ) ) );
}

void RootWindow::setProfs( IdTitleMap profList )
{
    ui->ComboBox_Config_Profession->clear();
    for( auto it = profList.begin(); it != profList.end(); ++it )
    {
        ui->ComboBox_Config_Profession->addItem( it.value(), it.key() );
    }
}

RootWindow::RootWindow( QWidget *parent ) :
QMainWindow( parent ),
ui( new Ui::RootWindow ),
_answerGroup( nullptr )/*,
_answersLay(nullptr)*/
{
    _selRadioAnss.clear();

    ui->setupUi( this );
    ui->stackedWidget->setCurrentIndex( PageIndex::RootWindow::Config );
    _jParser = JsonParser::instance( this );
    _netMan = new NetworkQueryManager( "127.0.0.1", 3434 );

    this->hide();

    connectSignals();
    _netMan->sendPullRequestProfList();

    AutorisationDialog _AuthForm( _netMan, _jParser );
    _AuthForm.exec();
}

RootWindow::~RootWindow()
{
    delete ui;
}

void RootWindow::on_ComboBox_Config_Profession_currentIndexChanged( int index )
{
    //  QString profId = ui->ComboBox_Config_Profession->itemData(index).toString();
    QString profId = ui->ComboBox_Config_Profession->currentData().toString();
    qDebug() << "profId >" << profId;
    _netMan->sendPullRequestLessonsList( profId );
    connect( _jParser, SIGNAL( takeLessons( IdTitleMap ) ),
             this, SLOT( setLessonsList( IdTitleMap ) ) );
}

void RootWindow::setLessonsList( IdTitleMap lessonsList)
{
    ui->ComboBox_Config_Lessons->clear();
    for( auto it = lessonsList.begin(); it != lessonsList.end(); ++it )
    {
        ui->ComboBox_Config_Lessons->addItem( it.value(), it.key() );
        qDebug() << "[RootWindow::setLessonsList] it.val: " << it.value() << " it.key:" << it.key()
            << ui->ComboBox_Config_Lessons->currentData().toString();

    }
}

void RootWindow::setThemesList( IdTitleMap themeList )
{
    ui->ComboBox_Config_Theme->clear();
    ui->ComboBox_Config_Theme->blockSignals( true );
    for( auto it = themeList.begin(); it != themeList.end(); ++it )
    {
        ui->ComboBox_Config_Theme->addItem( it.value(), it.key() );
        qDebug() << "[RootWindow::setThemesList] it.val: " << it.value() << " it.key:" << it.key();
    }
    ui->ComboBox_Config_Theme->blockSignals( false );
}

void RootWindow::setMaxQuestionsCount( qint64 maxCount )
{
    // ui->HorizontalSlider_Config_QuestionsCount->setMinimum(/*maxCount>5 ? 5: 0*/ 100);
}

void RootWindow::setProfsTree(IdTitleMap profTree, QTreeWidgetItem *selectedItem)
{
    qDebug() << "[RootWindow::setProfsTree]";
}



void RootWindow::setQuestions( QVector<strQuestions> &questions )
{
    _questions = questions;
    QString profession = ui->ComboBox_Config_Profession->currentText(),
        lesson = ui->ComboBox_Config_Lessons->currentText(),
        theme = ui->ComboBox_Config_Theme->currentText(),
        questionText = questions.first().text,
        questionType = questions.first().type;

    QButtonGroup *butGroup = new QButtonGroup( this );
    int rowCount = round( float( questions.count() / 5 ) ),
        colCount = round( float( questions.count() / rowCount ) );

    Qt::Alignment align;
    align = Qt::AlignLeft;
    //  QLayoutItem *layItem = new QLayoutItem;
    //    layItem
    TileLayout *layout = new TileLayout;
    QRect rect;
    rect.setWidth( 24 );
    rect.setHeight( 24 );
    rect.setTop( 6 );
    rect.setLeft( 6 );

    layout->setGeometry( rect );

    for( int j = 0; j < questions.count(); ++j )
    {

        Button *btn = new Button( QString::number( j + 1 ), j );
        //  ui->GLay_Tester_Questions->addWidget( btn, i + 1, j + 1, Qt::AlignTop );
        //        layout->addItem();
        layout->addWidget( btn );
        butGroup->addButton( btn, 1 );
        connect( btn, SIGNAL( selected( int ) ),
                 this, SLOT( questionSelected( int ) ) );
    }
    ui->scrolLay->setLayout( layout );
    /// \todo generate answers for firs question
    ui->Label_Tester_Profession->setText( profession );
    ui->Label_Tester_Lesson->setText( lesson );
    ui->Label_Tester_Theme->setText( theme );
    ui->Label_Tester_Question->setText( questionText );

    createAnswers( 0, questionType, _questions.first().answers );
}

void RootWindow::questionSelected( int number )
{
    strQuestions &strQs = _questions[number];
    ui->Label_Tester_Question->setText( strQs.text );

    createAnswers( number, strQs.type, strQs.answers );
}

void RootWindow::createAnswers( const int questionNum, const QString &type, QVector<strAnswers> &answers )
{
    if( _answerGroup )
    {
        delete _answerGroup;
    }
    _answerGroup = new QGroupBox( "Answers" );
    _answersLay = new QVBoxLayout( _answerGroup );
    ui->VLay_Tester_Answers->addWidget( _answerGroup );
    _answerGroup->setLayout( _answersLay );

    if( type == QuestionTypes::RADIO )
    {
        createRadioAnswers( answers, questionNum );
        return;
    }
    if( type == QuestionTypes::CHECK )
    {
        createCheckAnswers( answers, questionNum );
        return;
    }
    if( type == QuestionTypes::TEXT )
    {
        createTextAnswers( answers, questionNum );
        return;
    }
}

void RootWindow::answerRadioSelected( int qNum, int ansNum )
{
    _selRadioAnss.insert( qNum, ansNum );
}

void RootWindow::answerCheckSelected( int qNum, int ansNum )
{
    _selCheckAnss.insertMulti( qNum, ansNum );
}

void RootWindow::ansEntered( int qNum, const QString &text )
{
    _entAnss.insert( qNum, text );
}

void RootWindow::createRadioAnswers( QVector<strAnswers> &answers, int questionNum )
{
    for( int i = 0; i < answers.count(); ++i )
    {
        Radio *radio;
        qDebug() << "new Radio >" << questionNum << ">" << i;
        radio = new Radio( answers[i].text, questionNum, i );

        radio->setChecked( _selRadioAnss.value( questionNum ) == i
                           && !(_selRadioAnss.isEmpty())
                           && _selRadioAnss.contains( questionNum ) );

        connect( radio, SIGNAL( clicked( bool ) ),
                 radio, SLOT( ansSelected( bool ) ) );

        connect( radio, SIGNAL( ansSelected( int, int ) ),
                 this, SLOT( answerRadioSelected( int, int ) ) );

        _answersLay->addWidget( radio );
        /*        if( ! answers[i].wgt ){

                    radio = new QRadioButton;            почему это не работает выясним позже (всётки красивое решение)
                    answers[i].wgt = radio;
                    radio->setText( answers[i].text );
                    _answersLay->addWidget( answers[i].wgt );
                    }else{
                    qDebug() << "old Radio";
                    //            radio = qobject_cast<QRadioButton*>(answers[i].wgt);
                    _answersLay->addWidget( answers[i].wgt );
                    }*/
    }
}

void RootWindow::createCheckAnswers( QVector<strAnswers> &answers, int questionNum )
{
    for( int i = 0; i < answers.count(); ++i )
    {
        Check *check;
        qDebug() << "new Check >" << questionNum << ">" << i;
        check = new Check( answers[i].text, questionNum, i );
        bool ok1 = !(_selCheckAnss.isEmpty()),
            ok2 = _selCheckAnss.contains( questionNum ),       //      ____
            ok3 = false;                                       //     /   /
        //    /___/
        QList<int> vals = _selCheckAnss.values( questionNum ); //    \  /
        foreach( int val, vals )                               //     \/
        {                                                      //     /
            if( ok3 = val == i )                               //    /
                break;                                         //   *
            else continue;
        }

        check->setChecked( ok1 && ok2 && ok3 );

        connect( check, SIGNAL( clicked( bool ) ),
                 check, SLOT( ansSelected( bool ) ) );

        connect( check, SIGNAL( ansSelected( int, int ) ),
                 this, SLOT( answerCheckSelected( int, int ) ) );

        _answersLay->addWidget( check );
        /*       if (! answers[i].wgt ) {

                   answers[i].wgt = check;
                   check->setText(answers[i].text);
                   //    _answersLay->addWidget( check );
                   }else{
                   qDebug() << "old Check";
                   //            check = qobject_cast<QCheckBox*>(answers[i].wgt);
                   //    _answersLay->addWidget( answers[i].wgt );
                   }*/

    }
}

void RootWindow::createTextAnswers( QVector<strAnswers> &answers, int questionNum )
{
    Edit *edit;
    qDebug() << "new Edit";
    edit = new Edit( _entAnss.value( questionNum ), questionNum );

    connect( edit, SIGNAL( textEdited( QString ) ),
             edit, SLOT( ansEntered( QString ) ) );

    connect( edit, SIGNAL( ansSignalEntered( int, QString ) ),
             this, SLOT( ansEntered( int, QString ) ) );
    _answersLay->addWidget( edit );
}

void RootWindow::on_ComboBox_Config_Lessons_currentIndexChanged( int index )
{
    qDebug() << ui->ComboBox_Config_Lessons->currentData().toInt();
    QString lessonsId = ui->ComboBox_Config_Lessons->currentData().toString();
    qDebug() << "lessonsId" << lessonsId;
    _netMan->sendPullRequestThemesList( lessonsId );
    connect( _jParser, SIGNAL( takeThemes( IdTitleMap ) ),
             this, SLOT( setThemesList( IdTitleMap ) ) );
}

//void RootWindow::userChecked()
//{

//}



void RootWindow::on_ComboBox_Config_Theme_currentIndexChanged( int index )
{
    // нужно запросить максимальное количество вопросов в базе данных
    QString themeId = ui->ComboBox_Config_Theme->currentData().toString();
    qDebug() << "themeId" << themeId;
    //_netMan->sendPullRequestQuestionsCount(themeId);         // TODO : change that
    connect( _jParser, SIGNAL( takeQuestionsCount( qint64 ) ),
             this, SLOT( setMaxQuestionsCount( qint64 ) ) );
}

void RootWindow::on_PButton_Config_Begin_clicked()
{
    QString themeId = ui->ComboBox_Config_Theme->currentData().toString();
    qint64 questionsCount = ui->SBox_Config_needQCount->value(),
        answersCount = 5;
    _netMan->sendPullRequestQuestions( themeId, questionsCount, answersCount );
    connect( _jParser, SIGNAL( takeQuestions( QVector<strQuestions>& ) ),
             this, SLOT( setQuestions( QVector<strQuestions>& ) ) );
    ui->stackedWidget->setCurrentIndex( PageIndex::RootWindow::TestProcess );
}

// admin`ka
// web

// Questions base
void RootWindow::createTabelsTreeModel()
{
    QStringList topRowNames( { tr( "Professions" ), tr( "Lessons" ), tr( "Themes" ), tr( "Questions" ), tr( "Answers" ) } ),
        topRowWhatsThis( { "profession_id", "lesson_id", "theme_id", "question_id", "xz"  } ),
        subRowProfINames( { "Prof1", "Prof2" } ),
        subRowProfWhatThis( { "profId=1", "profId=2" } ),
        subRowLessonINames( { "lesson1", "lesson2" } ),
        subSubRowLessonWhatThis( { "lessonId=1", "lessonId=2" } );
    QVector<int> treesTypes{ Codes::ProfsTree,
        Codes::LessonsTree,
        Codes::ThemesTree,
        Codes::QuestionsTree,
        Codes::AnswersTree };


    // QTreeWidget *twg = ui->TreeWidget_Admin_QuestionsBase;

    //    ui->TreeWidget_Admin_QuestionsBase->setHeaderHidden( "topRowNames" );
    ui->TreeWidget_Admin_QuestionsBase->setSortingEnabled( false );

    topItems = addTreeChilds( ui->TreeWidget_Admin_QuestionsBase, topRowNames, topRowWhatsThis, treesTypes );

    connect( ui->TreeWidget_Admin_QuestionsBase, SIGNAL( itemPressed( QTreeWidgetItem*, int ) ),
             this, SLOT( itemWhats( QTreeWidgetItem*, int ) ) );
}

void RootWindow::itemWhats( QTreeWidgetItem *item, int column )
{
    int whatsTypes;
    QString whatsId;

    whatsTypes = item->whatsThis( 1 ).toInt();
    whatsId = item->whatsThis( 2 );
    //_selected = item->;
    if( whatsTypes == Codes::ProfsTree )
    {
        _netMan->sendPullRequestProfList();
        qDebug() << "[RootWindow::_itemChanged]> ProfsTree types> " << whatsTypes  << " id > " << whatsId;
    }
    if( whatsTypes == Codes::LessonsTree )
    {
        _netMan->sendPullRequestLessonsList( whatsId  );
        qDebug() << "[RootWindow::_itemChanged]> LessonsTree type> " << whatsTypes << " id > " << whatsId;
    }
    if( whatsTypes == Codes::ThemesTree )
    {
        _netMan->sendPullRequestThemesList(  whatsId  );
        qDebug() << "[RootWindow::_itemChanged]> ThemesTree types> " << whatsTypes << " id > " << whatsId;
    }
    if( whatsTypes == Codes::QuestionsTree )
    {
        //_netMan->sendPullRequestQuestions();
        qDebug() << "[RootWindow::_itemChanged]> QuestionsTree types>" << whatsTypes << " id > " << whatsId;
    }
    if( whatsTypes == Codes::AnswersTree )
    {
        //_netMan->sendPullRequestQuestions();
        qDebug() << "[RootWindow::_itemChanged]> AnswersTree types> " << whatsTypes << " id > " << whatsId;
    }

    // signals processing
    connect(_jParser, SIGNAL(takeSignalProfsTree(IdTitleMap)),
            this, SLOT(setProfsTree(IdTitleMap, item)));/*
    connect(_jParser, SIGNAL(takeSignalLessonsTree(IdTitleMap)),
            this, SLOT(setLessonsTree(IdTitleMap, item)));*/
}

TreeItems RootWindow::addTreeChilds( QTreeWidget *twg,
                                     const QStringList &itemsNames,
                                     const QStringList &whatsThis,
                                     const QVector<int> whatThisCol )
{
    QTreeWidgetItem *twgi = 0;
    TreeItems _items;

    for( int i = 0; i < itemsNames.count(); ++i )
    {
        twgi = new QTreeWidgetItem( twg );
        twgi->setText( 0, itemsNames.at( i ) );
        twgi->setWhatsThis( 1, QString::number( whatThisCol.at( i ) ) );
        twgi->setWhatsThis( 2, whatsThis.at( i ) );
        _items.push_back( twgi );
    }
    return _items;
}

TreeItems RootWindow::addTreeChilds( QTreeWidgetItem *twgi,
                                     const QStringList &itemsNames,
                                     const QStringList &whatsThis,
                                     const QVector<int> whatThisCol )
{
    QTreeWidgetItem *twgsi = 0;
    TreeItems _items;

    for( int i = 0; i < itemsNames.count(); ++i )
    {
        twgsi = new QTreeWidgetItem( twgi );
        twgsi->setText( 0, itemsNames.at( i ) );
        twgsi->setWhatsThis( 1, QString::number( whatThisCol.at( i ) ) );
        twgsi->setWhatsThis( 2, whatsThis.at( i ) );
        _items.push_back( twgsi );
    }
    return _items;
}

TreeItems RootWindow::addProfsTreeChilds( QTreeWidgetItem *parent,
                                          const QStringList &itemsNames,
                                          const QStringList &whatsThis )
{
    QVector<int> typesThis;
    for( int i = 0; i < itemsNames.count(); ++i )
    {
        typesThis.push_back( Codes::ProfsTree );
    }
    return addTreeChilds( parent, itemsNames, whatsThis, typesThis );
}

TreeItems RootWindow::addProfsTreeChilds( QTreeWidget *viewport,
                                          const QStringList &itemsNames,
                                          const QStringList &whatsThis )
{
    QVector<int> typesThis;
    for( int i = 0; i < itemsNames.count(); ++i )
    {
        typesThis.push_back( Codes::ProfsTree );
    }
    return addTreeChilds( viewport, itemsNames, whatsThis, typesThis );
}

TreeItems RootWindow::addLessonsTreeChilds( QTreeWidgetItem *parent,
                                            const QStringList &itemsNames,
                                            const QStringList &whatsThis )
{
    QVector<int> typesThis;
    for( int i = 0; i < itemsNames.count(); ++i )
    {
        typesThis.push_back( Codes::LessonsTree );
    }
    return addTreeChilds( parent, itemsNames, whatsThis, typesThis );
}

TreeItems RootWindow::addLessonsTreeChilds( QTreeWidget *viewport,
                                            const QStringList &itemsNames,
                                            const QStringList &whatsThis )
{
    QVector<int> typesThis;
    for( int i = 0; i < itemsNames.count(); ++i )
    {
        typesThis.push_back( Codes::LessonsTree );
    }
    return addTreeChilds( viewport, itemsNames, whatsThis, typesThis );
}

TreeItems RootWindow::addThemesTreeChilds( QTreeWidgetItem *parent,
                                           const QStringList &itemsNames,
                                           const QStringList &whatsThis )
{
    QVector<int> typesThis;
    for( int i = 0; i < itemsNames.count(); ++i )
    {
        typesThis.push_back( Codes::ThemesTree );
    }
    return addTreeChilds( parent, itemsNames, whatsThis, typesThis );
}

TreeItems RootWindow::addThemesTreeChilds( QTreeWidget *viewport,
                                           const QStringList &itemsNames,
                                           const QStringList &whatsThis )
{
    QVector<int> typesThis;
    for( int i = 0; i < itemsNames.count(); ++i )
    {
        typesThis.push_back( Codes::ThemesTree );
    }
    return addTreeChilds( viewport, itemsNames, whatsThis, typesThis );
}

void RootWindow::on_pushButton_4_clicked()
{
    createTabelsTreeModel();
    ui->stackedWidget->setCurrentIndex( PageIndex::RootWindow::Administr );
}

void RootWindow::on_PButton_Config_Back_clicked()
{

}

//void RootWindow::treeItemClicked(Q);


void RootWindow::on_TreeWidget_Admin_QuestionsBase_itemChanged( QTreeWidgetItem *item, int column )
{

    /* connect(_jParser, SIGNAL(takeSignalProfsTree(IdTitleMap)),
             this, SLOT(setProfsTree(IdTitleMap)));*/
}
