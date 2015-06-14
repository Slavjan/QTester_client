/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *Start;
    QVBoxLayout *verticalLayout_3;
    QComboBox *ComboBox_Start_User;
    QPushButton *PButton_Start_BeginTest;
    QPushButton *PButton_Start_Admin;
    QWidget *Login;
    QVBoxLayout *verticalLayout_2;
    QFormLayout *formLayout;
    QLabel *Label_Login_Login;
    QLineEdit *LineEdit_Login_Login;
    QLabel *Label_Login_Password;
    QLineEdit *LineEdit_Login_Password;
    QLabel *Label_Login_Error;
    QPushButton *PButton_Login_Login;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(232, 142);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        Start = new QWidget();
        Start->setObjectName(QStringLiteral("Start"));
        verticalLayout_3 = new QVBoxLayout(Start);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        ComboBox_Start_User = new QComboBox(Start);
        ComboBox_Start_User->setObjectName(QStringLiteral("ComboBox_Start_User"));

        verticalLayout_3->addWidget(ComboBox_Start_User);

        PButton_Start_BeginTest = new QPushButton(Start);
        PButton_Start_BeginTest->setObjectName(QStringLiteral("PButton_Start_BeginTest"));

        verticalLayout_3->addWidget(PButton_Start_BeginTest);

        PButton_Start_Admin = new QPushButton(Start);
        PButton_Start_Admin->setObjectName(QStringLiteral("PButton_Start_Admin"));

        verticalLayout_3->addWidget(PButton_Start_Admin);

        stackedWidget->addWidget(Start);
        Login = new QWidget();
        Login->setObjectName(QStringLiteral("Login"));
        verticalLayout_2 = new QVBoxLayout(Login);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        Label_Login_Login = new QLabel(Login);
        Label_Login_Login->setObjectName(QStringLiteral("Label_Login_Login"));

        formLayout->setWidget(0, QFormLayout::LabelRole, Label_Login_Login);

        LineEdit_Login_Login = new QLineEdit(Login);
        LineEdit_Login_Login->setObjectName(QStringLiteral("LineEdit_Login_Login"));

        formLayout->setWidget(0, QFormLayout::FieldRole, LineEdit_Login_Login);

        Label_Login_Password = new QLabel(Login);
        Label_Login_Password->setObjectName(QStringLiteral("Label_Login_Password"));

        formLayout->setWidget(1, QFormLayout::LabelRole, Label_Login_Password);

        LineEdit_Login_Password = new QLineEdit(Login);
        LineEdit_Login_Password->setObjectName(QStringLiteral("LineEdit_Login_Password"));

        formLayout->setWidget(1, QFormLayout::FieldRole, LineEdit_Login_Password);

        Label_Login_Error = new QLabel(Login);
        Label_Login_Error->setObjectName(QStringLiteral("Label_Login_Error"));
        Label_Login_Error->setStyleSheet(QStringLiteral("color:red"));

        formLayout->setWidget(2, QFormLayout::FieldRole, Label_Login_Error);


        verticalLayout_2->addLayout(formLayout);

        PButton_Login_Login = new QPushButton(Login);
        PButton_Login_Login->setObjectName(QStringLiteral("PButton_Login_Login"));

        verticalLayout_2->addWidget(PButton_Login_Login);

        stackedWidget->addWidget(Login);

        verticalLayout->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        PButton_Start_BeginTest->setText(QApplication::translate("MainWindow", "Begin new test", 0));
        PButton_Start_Admin->setText(QApplication::translate("MainWindow", "Admitistration", 0));
        Label_Login_Login->setText(QApplication::translate("MainWindow", "Login:", 0));
        Label_Login_Password->setText(QApplication::translate("MainWindow", "Password:", 0));
        Label_Login_Error->setText(QApplication::translate("MainWindow", "ERROR", 0));
        PButton_Login_Login->setText(QApplication::translate("MainWindow", "Login", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
