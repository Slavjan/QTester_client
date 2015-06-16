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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RootWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
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
    QGroupBox *GroupBox_Tester_Answers;
    QVBoxLayout *VLay_Tester_Answers;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton;
    QScrollArea *scrollArea;
    QWidget *GLay_Tester_Questions;
    QGridLayout *gridLayout_2;

    void setupUi(QMainWindow *RootWindow)
    {
        if (RootWindow->objectName().isEmpty())
            RootWindow->setObjectName(QStringLiteral("RootWindow"));
        RootWindow->resize(630, 367);
        centralwidget = new QWidget(RootWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
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

        verticalLayout_8->addWidget(Label_Tester_Question);


        verticalLayout_7->addWidget(groupBox_3);


        verticalLayout_4->addWidget(GroupBox_Tester_Examinee);

        GroupBox_Tester_Answers = new QGroupBox(groupBox_2);
        GroupBox_Tester_Answers->setObjectName(QStringLiteral("GroupBox_Tester_Answers"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(GroupBox_Tester_Answers->sizePolicy().hasHeightForWidth());
        GroupBox_Tester_Answers->setSizePolicy(sizePolicy3);
        GroupBox_Tester_Answers->setMinimumSize(QSize(0, 0));
        VLay_Tester_Answers = new QVBoxLayout(GroupBox_Tester_Answers);
        VLay_Tester_Answers->setObjectName(QStringLiteral("VLay_Tester_Answers"));

        verticalLayout_4->addWidget(GroupBox_Tester_Answers);


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
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy4);
        scrollArea->setMinimumSize(QSize(150, 0));
        scrollArea->setMaximumSize(QSize(300, 16777215));
        scrollArea->setWidgetResizable(true);
        scrollArea->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        GLay_Tester_Questions = new QWidget();
        GLay_Tester_Questions->setObjectName(QStringLiteral("GLay_Tester_Questions"));
        GLay_Tester_Questions->setGeometry(QRect(0, 0, 148, 298));
        gridLayout_2 = new QGridLayout(GLay_Tester_Questions);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        scrollArea->setWidget(GLay_Tester_Questions);

        verticalLayout_3->addWidget(scrollArea);


        horizontalLayout_3->addLayout(verticalLayout_3);

        stackedWidget->addWidget(page_2);

        verticalLayout_2->addWidget(stackedWidget);

        RootWindow->setCentralWidget(centralwidget);

        retranslateUi(RootWindow);
        QObject::connect(HorizontalSlider_Config_QuestionsCount, SIGNAL(valueChanged(int)), SBox_Config_needQCount, SLOT(setValue(int)));
        QObject::connect(SBox_Config_needQCount, SIGNAL(valueChanged(int)), HorizontalSlider_Config_QuestionsCount, SLOT(setValue(int)));

        stackedWidget->setCurrentIndex(0);


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
        GroupBox_Tester_Answers->setTitle(QApplication::translate("RootWindow", "Answers", 0));
        pushButton->setText(QApplication::translate("RootWindow", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class RootWindow: public Ui_RootWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOTWINDOW_H
