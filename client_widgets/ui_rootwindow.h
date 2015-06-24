/********************************************************************************
** Form generated from reading UI file 'rootwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROOTWINDOW_H
#define UI_ROOTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RootWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_9;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *label_2;
    QComboBox *ComboBox_Config_Profession;
    QLabel *label_3;
    QComboBox *ComboBox_Config_Lessons;
    QLabel *label_5;
    QComboBox *ComboBox_Config_Theme;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout;
    QSlider *HorizontalSlider_Config_QuestionsCount;
    QSpinBox *SBox_Config_needQCount;
    QLabel *label_6;
    QSpinBox *SBox_Config_maxQCount;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_4;
    QPushButton *PButton_Config_Back;
    QPushButton *PButton_Config_Begin;
    QWidget *page_2;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *GroupBox_Tester_Examinee;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QVBoxLayout *verticalLayout_6;
    QLabel *Label_Tester_Profession;
    QLabel *Label_Tester_Lesson;
    QLabel *Label_Tester_Theme;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_8;
    QLabel *Label_Tester_Question;
    QVBoxLayout *VLay_Tester_Answers;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton;
    QScrollArea *scrollArea;
    QWidget *scrolLay;
    QGridLayout *gridLayout_2;
    QWidget *page_3;
    QGridLayout *gridLayout;
    QTabWidget *TabWidget_Admin;
    QWidget *TabWidget_Admin_tabUsers;
    QGridLayout *gridLayout_11;
    QGroupBox *GroupBox_Admin_tabUsers_Users;
    QGridLayout *gridLayout_5;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_11;
    QLineEdit *LineEdit_Admin_tabUsers_firstName;
    QLineEdit *LineEdit_Admin_tabUsers_secondName;
    QLineEdit *LineEdit_Admin_tabUsers_Login;
    QLineEdit *LineEdit_Admin_tabUsers_Password;
    QVBoxLayout *verticalLayout_12;
    QComboBox *ComboBox_Admin_tabUsers_UserGroup;
    QPushButton *PushButton_Admin_tabUsers_Add;
    QPushButton *PushButton_Admin_tabUsers_Edit;
    QPushButton *PushButton_Admin_tabUsers_Delete;
    QHBoxLayout *horizontalLayout_7;
    QTableWidget *TableWidget_Admin_tabUsers_usersGroups;
    QTableWidget *TableWidget_Admin_tabUsers_Users;
    QGroupBox *GroupBox_Admin_tabUsers_Web;
    QGridLayout *gridLayout_12;
    QLineEdit *LineEdit_Admin_tabUsers_IP;
    QPushButton *PushButton_Admin_tabUsers_Connect;
    QSpinBox *SpinBoxAdmin_tabUsers_Port;
    QWidget *TabWidget_Admin_tabQuestions;
    QGridLayout *gridLayout_3;
    QGroupBox *GroupBox_Admin_tabQuestions_Tables_Workspace;
    QGridLayout *gridLayout_6;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_9;
    QTableWidget *tableWidget;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_10;
    QTableWidget *tableWidget_2;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout_8;
    QGridLayout *gridLayout_7;
    QGroupBox *GroupBox_Admin_tabQuestions_QuestParams;
    QGridLayout *gridLayout_4;
    QHBoxLayout *HorizontalLayout_Admin_tabQuestions_QuestionsParams;

    void setupUi(QMainWindow *RootWindow)
    {
        if (RootWindow->objectName().isEmpty())
            RootWindow->setObjectName(QStringLiteral("RootWindow"));
        RootWindow->resize(682, 431);
        centralwidget = new QWidget(RootWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_9 = new QVBoxLayout(centralwidget);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        verticalLayout = new QVBoxLayout(page);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(page);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(label);

        groupBox = new QGroupBox(page);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        ComboBox_Config_Profession = new QComboBox(groupBox);
        ComboBox_Config_Profession->setObjectName(QStringLiteral("ComboBox_Config_Profession"));

        formLayout->setWidget(0, QFormLayout::FieldRole, ComboBox_Config_Profession);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        ComboBox_Config_Lessons = new QComboBox(groupBox);
        ComboBox_Config_Lessons->setObjectName(QStringLiteral("ComboBox_Config_Lessons"));

        formLayout->setWidget(1, QFormLayout::FieldRole, ComboBox_Config_Lessons);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_5);

        ComboBox_Config_Theme = new QComboBox(groupBox);
        ComboBox_Config_Theme->setObjectName(QStringLiteral("ComboBox_Config_Theme"));

        formLayout->setWidget(2, QFormLayout::FieldRole, ComboBox_Config_Theme);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        HorizontalSlider_Config_QuestionsCount = new QSlider(groupBox);
        HorizontalSlider_Config_QuestionsCount->setObjectName(QStringLiteral("HorizontalSlider_Config_QuestionsCount"));
        HorizontalSlider_Config_QuestionsCount->setMinimum(5);
        HorizontalSlider_Config_QuestionsCount->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(HorizontalSlider_Config_QuestionsCount);

        SBox_Config_needQCount = new QSpinBox(groupBox);
        SBox_Config_needQCount->setObjectName(QStringLiteral("SBox_Config_needQCount"));
        SBox_Config_needQCount->setMinimum(5);

        horizontalLayout->addWidget(SBox_Config_needQCount);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout->addWidget(label_6);

        SBox_Config_maxQCount = new QSpinBox(groupBox);
        SBox_Config_maxQCount->setObjectName(QStringLiteral("SBox_Config_maxQCount"));
        SBox_Config_maxQCount->setContextMenuPolicy(Qt::DefaultContextMenu);
        SBox_Config_maxQCount->setReadOnly(true);
        SBox_Config_maxQCount->setButtonSymbols(QAbstractSpinBox::NoButtons);
        SBox_Config_maxQCount->setMaximum(100);
        SBox_Config_maxQCount->setValue(100);

        horizontalLayout->addWidget(SBox_Config_maxQCount);


        formLayout->setLayout(3, QFormLayout::FieldRole, horizontalLayout);


        verticalLayout->addWidget(groupBox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton_4 = new QPushButton(page);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        horizontalLayout_2->addWidget(pushButton_4);

        PButton_Config_Back = new QPushButton(page);
        PButton_Config_Back->setObjectName(QStringLiteral("PButton_Config_Back"));

        horizontalLayout_2->addWidget(PButton_Config_Back);

        PButton_Config_Begin = new QPushButton(page);
        PButton_Config_Begin->setObjectName(QStringLiteral("PButton_Config_Begin"));
        PButton_Config_Begin->setEnabled(true);

        horizontalLayout_2->addWidget(PButton_Config_Begin);


        verticalLayout->addLayout(horizontalLayout_2);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        horizontalLayout_3 = new QHBoxLayout(page_2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        groupBox_2 = new QGroupBox(page_2);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy1);
        verticalLayout_4 = new QVBoxLayout(groupBox_2);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, -1);
        GroupBox_Tester_Examinee = new QGroupBox(groupBox_2);
        GroupBox_Tester_Examinee->setObjectName(QStringLiteral("GroupBox_Tester_Examinee"));
        sizePolicy.setHeightForWidth(GroupBox_Tester_Examinee->sizePolicy().hasHeightForWidth());
        GroupBox_Tester_Examinee->setSizePolicy(sizePolicy);
        verticalLayout_7 = new QVBoxLayout(GroupBox_Tester_Examinee);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setSizeConstraint(QLayout::SetFixedSize);
        verticalLayout_5->setContentsMargins(-1, -1, 1, -1);
        label_7 = new QLabel(GroupBox_Tester_Examinee);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_5->addWidget(label_7);

        label_8 = new QLabel(GroupBox_Tester_Examinee);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout_5->addWidget(label_8);

        label_9 = new QLabel(GroupBox_Tester_Examinee);
        label_9->setObjectName(QStringLiteral("label_9"));

        verticalLayout_5->addWidget(label_9);


        horizontalLayout_4->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setSizeConstraint(QLayout::SetMaximumSize);
        verticalLayout_6->setContentsMargins(-1, -1, 100, -1);
        Label_Tester_Profession = new QLabel(GroupBox_Tester_Examinee);
        Label_Tester_Profession->setObjectName(QStringLiteral("Label_Tester_Profession"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(Label_Tester_Profession->sizePolicy().hasHeightForWidth());
        Label_Tester_Profession->setSizePolicy(sizePolicy2);
        Label_Tester_Profession->setMaximumSize(QSize(300, 16777215));

        verticalLayout_6->addWidget(Label_Tester_Profession);

        Label_Tester_Lesson = new QLabel(GroupBox_Tester_Examinee);
        Label_Tester_Lesson->setObjectName(QStringLiteral("Label_Tester_Lesson"));
        sizePolicy2.setHeightForWidth(Label_Tester_Lesson->sizePolicy().hasHeightForWidth());
        Label_Tester_Lesson->setSizePolicy(sizePolicy2);
        Label_Tester_Lesson->setMaximumSize(QSize(300, 16777215));

        verticalLayout_6->addWidget(Label_Tester_Lesson);

        Label_Tester_Theme = new QLabel(GroupBox_Tester_Examinee);
        Label_Tester_Theme->setObjectName(QStringLiteral("Label_Tester_Theme"));
        sizePolicy2.setHeightForWidth(Label_Tester_Theme->sizePolicy().hasHeightForWidth());
        Label_Tester_Theme->setSizePolicy(sizePolicy2);
        Label_Tester_Theme->setMaximumSize(QSize(300, 16777215));

        verticalLayout_6->addWidget(Label_Tester_Theme);


        horizontalLayout_4->addLayout(verticalLayout_6);


        verticalLayout_7->addLayout(horizontalLayout_4);

        groupBox_3 = new QGroupBox(GroupBox_Tester_Examinee);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        sizePolicy.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy);
        verticalLayout_8 = new QVBoxLayout(groupBox_3);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        Label_Tester_Question = new QLabel(groupBox_3);
        Label_Tester_Question->setObjectName(QStringLiteral("Label_Tester_Question"));
        Label_Tester_Question->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        Label_Tester_Question->setWordWrap(true);

        verticalLayout_8->addWidget(Label_Tester_Question);


        verticalLayout_7->addWidget(groupBox_3);


        verticalLayout_4->addWidget(GroupBox_Tester_Examinee);

        VLay_Tester_Answers = new QVBoxLayout();
        VLay_Tester_Answers->setObjectName(QStringLiteral("VLay_Tester_Answers"));

        verticalLayout_4->addLayout(VLay_Tester_Answers);


        horizontalLayout_3->addWidget(groupBox_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetMinimumSize);
        pushButton = new QPushButton(page_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(150, 0));
        pushButton->setMaximumSize(QSize(300, 16777215));

        verticalLayout_3->addWidget(pushButton);

        scrollArea = new QScrollArea(page_2);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy3);
        scrollArea->setMinimumSize(QSize(150, 0));
        scrollArea->setMaximumSize(QSize(300, 16777215));
        scrollArea->setWidgetResizable(true);
        scrollArea->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        scrolLay = new QWidget();
        scrolLay->setObjectName(QStringLiteral("scrolLay"));
        scrolLay->setGeometry(QRect(0, 0, 148, 364));
        gridLayout_2 = new QGridLayout(scrolLay);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        scrollArea->setWidget(scrolLay);

        verticalLayout_3->addWidget(scrollArea);


        horizontalLayout_3->addLayout(verticalLayout_3);

        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        gridLayout = new QGridLayout(page_3);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        TabWidget_Admin = new QTabWidget(page_3);
        TabWidget_Admin->setObjectName(QStringLiteral("TabWidget_Admin"));
        TabWidget_Admin_tabUsers = new QWidget();
        TabWidget_Admin_tabUsers->setObjectName(QStringLiteral("TabWidget_Admin_tabUsers"));
        QSizePolicy sizePolicy4(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(TabWidget_Admin_tabUsers->sizePolicy().hasHeightForWidth());
        TabWidget_Admin_tabUsers->setSizePolicy(sizePolicy4);
        gridLayout_11 = new QGridLayout(TabWidget_Admin_tabUsers);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        GroupBox_Admin_tabUsers_Users = new QGroupBox(TabWidget_Admin_tabUsers);
        GroupBox_Admin_tabUsers_Users->setObjectName(QStringLiteral("GroupBox_Admin_tabUsers_Users"));
        gridLayout_5 = new QGridLayout(GroupBox_Admin_tabUsers_Users);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        LineEdit_Admin_tabUsers_firstName = new QLineEdit(GroupBox_Admin_tabUsers_Users);
        LineEdit_Admin_tabUsers_firstName->setObjectName(QStringLiteral("LineEdit_Admin_tabUsers_firstName"));

        verticalLayout_11->addWidget(LineEdit_Admin_tabUsers_firstName);

        LineEdit_Admin_tabUsers_secondName = new QLineEdit(GroupBox_Admin_tabUsers_Users);
        LineEdit_Admin_tabUsers_secondName->setObjectName(QStringLiteral("LineEdit_Admin_tabUsers_secondName"));

        verticalLayout_11->addWidget(LineEdit_Admin_tabUsers_secondName);

        LineEdit_Admin_tabUsers_Login = new QLineEdit(GroupBox_Admin_tabUsers_Users);
        LineEdit_Admin_tabUsers_Login->setObjectName(QStringLiteral("LineEdit_Admin_tabUsers_Login"));

        verticalLayout_11->addWidget(LineEdit_Admin_tabUsers_Login);

        LineEdit_Admin_tabUsers_Password = new QLineEdit(GroupBox_Admin_tabUsers_Users);
        LineEdit_Admin_tabUsers_Password->setObjectName(QStringLiteral("LineEdit_Admin_tabUsers_Password"));

        verticalLayout_11->addWidget(LineEdit_Admin_tabUsers_Password);


        horizontalLayout_5->addLayout(verticalLayout_11);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        ComboBox_Admin_tabUsers_UserGroup = new QComboBox(GroupBox_Admin_tabUsers_Users);
        ComboBox_Admin_tabUsers_UserGroup->setObjectName(QStringLiteral("ComboBox_Admin_tabUsers_UserGroup"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(ComboBox_Admin_tabUsers_UserGroup->sizePolicy().hasHeightForWidth());
        ComboBox_Admin_tabUsers_UserGroup->setSizePolicy(sizePolicy5);

        verticalLayout_12->addWidget(ComboBox_Admin_tabUsers_UserGroup);

        PushButton_Admin_tabUsers_Add = new QPushButton(GroupBox_Admin_tabUsers_Users);
        PushButton_Admin_tabUsers_Add->setObjectName(QStringLiteral("PushButton_Admin_tabUsers_Add"));

        verticalLayout_12->addWidget(PushButton_Admin_tabUsers_Add);

        PushButton_Admin_tabUsers_Edit = new QPushButton(GroupBox_Admin_tabUsers_Users);
        PushButton_Admin_tabUsers_Edit->setObjectName(QStringLiteral("PushButton_Admin_tabUsers_Edit"));

        verticalLayout_12->addWidget(PushButton_Admin_tabUsers_Edit);

        PushButton_Admin_tabUsers_Delete = new QPushButton(GroupBox_Admin_tabUsers_Users);
        PushButton_Admin_tabUsers_Delete->setObjectName(QStringLiteral("PushButton_Admin_tabUsers_Delete"));

        verticalLayout_12->addWidget(PushButton_Admin_tabUsers_Delete);


        horizontalLayout_5->addLayout(verticalLayout_12);


        gridLayout_5->addLayout(horizontalLayout_5, 0, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        TableWidget_Admin_tabUsers_usersGroups = new QTableWidget(GroupBox_Admin_tabUsers_Users);
        TableWidget_Admin_tabUsers_usersGroups->setObjectName(QStringLiteral("TableWidget_Admin_tabUsers_usersGroups"));

        horizontalLayout_7->addWidget(TableWidget_Admin_tabUsers_usersGroups);

        TableWidget_Admin_tabUsers_Users = new QTableWidget(GroupBox_Admin_tabUsers_Users);
        TableWidget_Admin_tabUsers_Users->setObjectName(QStringLiteral("TableWidget_Admin_tabUsers_Users"));

        horizontalLayout_7->addWidget(TableWidget_Admin_tabUsers_Users);


        gridLayout_5->addLayout(horizontalLayout_7, 1, 0, 1, 1);


        gridLayout_11->addWidget(GroupBox_Admin_tabUsers_Users, 0, 0, 1, 1);

        GroupBox_Admin_tabUsers_Web = new QGroupBox(TabWidget_Admin_tabUsers);
        GroupBox_Admin_tabUsers_Web->setObjectName(QStringLiteral("GroupBox_Admin_tabUsers_Web"));
        gridLayout_12 = new QGridLayout(GroupBox_Admin_tabUsers_Web);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        LineEdit_Admin_tabUsers_IP = new QLineEdit(GroupBox_Admin_tabUsers_Web);
        LineEdit_Admin_tabUsers_IP->setObjectName(QStringLiteral("LineEdit_Admin_tabUsers_IP"));

        gridLayout_12->addWidget(LineEdit_Admin_tabUsers_IP, 0, 0, 1, 1);

        PushButton_Admin_tabUsers_Connect = new QPushButton(GroupBox_Admin_tabUsers_Web);
        PushButton_Admin_tabUsers_Connect->setObjectName(QStringLiteral("PushButton_Admin_tabUsers_Connect"));

        gridLayout_12->addWidget(PushButton_Admin_tabUsers_Connect, 0, 2, 1, 1);

        SpinBoxAdmin_tabUsers_Port = new QSpinBox(GroupBox_Admin_tabUsers_Web);
        SpinBoxAdmin_tabUsers_Port->setObjectName(QStringLiteral("SpinBoxAdmin_tabUsers_Port"));
        QSizePolicy sizePolicy6(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(SpinBoxAdmin_tabUsers_Port->sizePolicy().hasHeightForWidth());
        SpinBoxAdmin_tabUsers_Port->setSizePolicy(sizePolicy6);
        SpinBoxAdmin_tabUsers_Port->setMinimumSize(QSize(128, 23));
        SpinBoxAdmin_tabUsers_Port->setMaximumSize(QSize(128, 23));
        SpinBoxAdmin_tabUsers_Port->setMinimum(1616);
        SpinBoxAdmin_tabUsers_Port->setMaximum(6464);
        SpinBoxAdmin_tabUsers_Port->setValue(3434);

        gridLayout_12->addWidget(SpinBoxAdmin_tabUsers_Port, 0, 1, 1, 1);

        GroupBox_Admin_tabUsers_Users->raise();
        PushButton_Admin_tabUsers_Connect->raise();
        LineEdit_Admin_tabUsers_IP->raise();
        SpinBoxAdmin_tabUsers_Port->raise();

        gridLayout_11->addWidget(GroupBox_Admin_tabUsers_Web, 1, 0, 1, 1);

        TabWidget_Admin->addTab(TabWidget_Admin_tabUsers, QString());
        TabWidget_Admin_tabQuestions = new QWidget();
        TabWidget_Admin_tabQuestions->setObjectName(QStringLiteral("TabWidget_Admin_tabQuestions"));
        gridLayout_3 = new QGridLayout(TabWidget_Admin_tabQuestions);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(6, 0, 6, 6);
        GroupBox_Admin_tabQuestions_Tables_Workspace = new QGroupBox(TabWidget_Admin_tabQuestions);
        GroupBox_Admin_tabQuestions_Tables_Workspace->setObjectName(QStringLiteral("GroupBox_Admin_tabQuestions_Tables_Workspace"));
        QSizePolicy sizePolicy7(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(GroupBox_Admin_tabQuestions_Tables_Workspace->sizePolicy().hasHeightForWidth());
        GroupBox_Admin_tabQuestions_Tables_Workspace->setSizePolicy(sizePolicy7);
        gridLayout_6 = new QGridLayout(GroupBox_Admin_tabQuestions_Tables_Workspace);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setSizeConstraint(QLayout::SetMaximumSize);
        groupBox_4 = new QGroupBox(GroupBox_Admin_tabQuestions_Tables_Workspace);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        gridLayout_9 = new QGridLayout(groupBox_4);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        tableWidget = new QTableWidget(groupBox_4);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        gridLayout_9->addWidget(tableWidget, 0, 0, 1, 1);


        horizontalLayout_6->addWidget(groupBox_4);

        groupBox_6 = new QGroupBox(GroupBox_Admin_tabQuestions_Tables_Workspace);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        gridLayout_10 = new QGridLayout(groupBox_6);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        tableWidget_2 = new QTableWidget(groupBox_6);
        tableWidget_2->setObjectName(QStringLiteral("tableWidget_2"));

        gridLayout_10->addWidget(tableWidget_2, 0, 0, 1, 1);


        horizontalLayout_6->addWidget(groupBox_6);


        verticalLayout_2->addLayout(horizontalLayout_6);

        groupBox_7 = new QGroupBox(GroupBox_Admin_tabQuestions_Tables_Workspace);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        QSizePolicy sizePolicy8(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(groupBox_7->sizePolicy().hasHeightForWidth());
        groupBox_7->setSizePolicy(sizePolicy8);
        gridLayout_8 = new QGridLayout(groupBox_7);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));

        gridLayout_8->addLayout(gridLayout_7, 0, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox_7);


        gridLayout_6->addLayout(verticalLayout_2, 0, 0, 1, 1);


        gridLayout_3->addWidget(GroupBox_Admin_tabQuestions_Tables_Workspace, 2, 0, 1, 1);

        GroupBox_Admin_tabQuestions_QuestParams = new QGroupBox(TabWidget_Admin_tabQuestions);
        GroupBox_Admin_tabQuestions_QuestParams->setObjectName(QStringLiteral("GroupBox_Admin_tabQuestions_QuestParams"));
        gridLayout_4 = new QGridLayout(GroupBox_Admin_tabQuestions_QuestParams);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        HorizontalLayout_Admin_tabQuestions_QuestionsParams = new QHBoxLayout();
        HorizontalLayout_Admin_tabQuestions_QuestionsParams->setObjectName(QStringLiteral("HorizontalLayout_Admin_tabQuestions_QuestionsParams"));

        gridLayout_4->addLayout(HorizontalLayout_Admin_tabQuestions_QuestionsParams, 0, 0, 1, 1);


        gridLayout_3->addWidget(GroupBox_Admin_tabQuestions_QuestParams, 0, 0, 1, 1);

        TabWidget_Admin->addTab(TabWidget_Admin_tabQuestions, QString());

        gridLayout->addWidget(TabWidget_Admin, 0, 0, 1, 1);

        stackedWidget->addWidget(page_3);

        verticalLayout_9->addWidget(stackedWidget);

        RootWindow->setCentralWidget(centralwidget);

        retranslateUi(RootWindow);
        QObject::connect(HorizontalSlider_Config_QuestionsCount, SIGNAL(valueChanged(int)), SBox_Config_needQCount, SLOT(setValue(int)));
        QObject::connect(SBox_Config_needQCount, SIGNAL(valueChanged(int)), HorizontalSlider_Config_QuestionsCount, SLOT(setValue(int)));

        stackedWidget->setCurrentIndex(2);
        TabWidget_Admin->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(RootWindow);
    } // setupUi

    void retranslateUi(QMainWindow *RootWindow)
    {
        RootWindow->setWindowTitle(QApplication::translate("RootWindow", "MainWindow", 0));
        label->setText(QApplication::translate("RootWindow", "TextLabel", 0));
        groupBox->setTitle(QApplication::translate("RootWindow", "Test configuration", 0));
        label_2->setText(QApplication::translate("RootWindow", "Profession:", 0));
        label_3->setText(QApplication::translate("RootWindow", "Lesson:", 0));
        label_5->setText(QApplication::translate("RootWindow", "Theme", 0));
        label_4->setText(QApplication::translate("RootWindow", "Questions count:", 0));
        label_6->setText(QApplication::translate("RootWindow", "/", 0));
        pushButton_4->setText(QApplication::translate("RootWindow", "Admin`ka", 0));
        PButton_Config_Back->setText(QApplication::translate("RootWindow", "Back", 0));
        PButton_Config_Begin->setText(QApplication::translate("RootWindow", "Begin", 0));
        groupBox_2->setTitle(QString());
        GroupBox_Tester_Examinee->setTitle(QString());
        label_7->setText(QApplication::translate("RootWindow", "Profession:", 0));
        label_8->setText(QApplication::translate("RootWindow", "Lesson:", 0));
        label_9->setText(QApplication::translate("RootWindow", "Theme:", 0));
        Label_Tester_Profession->setText(QApplication::translate("RootWindow", "_profession", 0));
        Label_Tester_Lesson->setText(QApplication::translate("RootWindow", "_lesson", 0));
        Label_Tester_Theme->setText(QApplication::translate("RootWindow", "_theme", 0));
        groupBox_3->setTitle(QApplication::translate("RootWindow", "Question", 0));
        Label_Tester_Question->setText(QApplication::translate("RootWindow", "Question Text", 0));
        pushButton->setText(QApplication::translate("RootWindow", "PushButton", 0));
        GroupBox_Admin_tabUsers_Users->setTitle(QApplication::translate("RootWindow", "Users", 0));
        LineEdit_Admin_tabUsers_firstName->setPlaceholderText(QApplication::translate("RootWindow", "First name", 0));
        LineEdit_Admin_tabUsers_secondName->setPlaceholderText(QApplication::translate("RootWindow", "Second name", 0));
        LineEdit_Admin_tabUsers_Login->setPlaceholderText(QApplication::translate("RootWindow", "Login", 0));
        LineEdit_Admin_tabUsers_Password->setPlaceholderText(QApplication::translate("RootWindow", "Password", 0));
        PushButton_Admin_tabUsers_Add->setText(QApplication::translate("RootWindow", "Add", 0));
        PushButton_Admin_tabUsers_Edit->setText(QApplication::translate("RootWindow", "Edit", 0));
        PushButton_Admin_tabUsers_Delete->setText(QApplication::translate("RootWindow", "Delete", 0));
        GroupBox_Admin_tabUsers_Web->setTitle(QApplication::translate("RootWindow", "Web settings", 0));
        PushButton_Admin_tabUsers_Connect->setText(QApplication::translate("RootWindow", "Connect", 0));
        TabWidget_Admin->setTabText(TabWidget_Admin->indexOf(TabWidget_Admin_tabUsers), QApplication::translate("RootWindow", "Tab 1", 0));
        GroupBox_Admin_tabQuestions_Tables_Workspace->setTitle(QApplication::translate("RootWindow", "Working with questions", 0));
        groupBox_4->setTitle(QApplication::translate("RootWindow", "Questions", 0));
        groupBox_6->setTitle(QApplication::translate("RootWindow", "Answers", 0));
        groupBox_7->setTitle(QApplication::translate("RootWindow", "Work space", 0));
        GroupBox_Admin_tabQuestions_QuestParams->setTitle(QApplication::translate("RootWindow", "Questions parameters", 0));
        TabWidget_Admin->setTabText(TabWidget_Admin->indexOf(TabWidget_Admin_tabQuestions), QApplication::translate("RootWindow", "Tab 2", 0));
    } // retranslateUi

};

namespace Ui {
    class RootWindow: public Ui_RootWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOTWINDOW_H
