/********************************************************************************
** Form generated from reading UI file 'autorisationdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTORISATIONDIALOG_H
#define UI_AUTORISATIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AutorisationDialog
{
public:
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_2;
    QComboBox *ComboBox_Auth_User;
    QPushButton *PButton_Auth_Begin;
    QPushButton *pushButton_2;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *LEdit_Login_Login;
    QLineEdit *LEdit_Login_Password;
    QPushButton *pushButton;

    void setupUi(QDialog *AutorisationDialog)
    {
        if (AutorisationDialog->objectName().isEmpty())
            AutorisationDialog->setObjectName(QStringLiteral("AutorisationDialog"));
        AutorisationDialog->resize(195, 123);
        AutorisationDialog->setMaximumSize(QSize(195, 123));
        verticalLayout = new QVBoxLayout(AutorisationDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        stackedWidget = new QStackedWidget(AutorisationDialog);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        verticalLayout_2 = new QVBoxLayout(page);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        ComboBox_Auth_User = new QComboBox(page);
        ComboBox_Auth_User->setObjectName(QStringLiteral("ComboBox_Auth_User"));

        verticalLayout_2->addWidget(ComboBox_Auth_User);

        PButton_Auth_Begin = new QPushButton(page);
        PButton_Auth_Begin->setObjectName(QStringLiteral("PButton_Auth_Begin"));

        verticalLayout_2->addWidget(PButton_Auth_Begin);

        pushButton_2 = new QPushButton(page);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout_2->addWidget(pushButton_2);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        verticalLayout_3 = new QVBoxLayout(page_2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        LEdit_Login_Login = new QLineEdit(page_2);
        LEdit_Login_Login->setObjectName(QStringLiteral("LEdit_Login_Login"));

        verticalLayout_3->addWidget(LEdit_Login_Login);

        LEdit_Login_Password = new QLineEdit(page_2);
        LEdit_Login_Password->setObjectName(QStringLiteral("LEdit_Login_Password"));

        verticalLayout_3->addWidget(LEdit_Login_Password);

        pushButton = new QPushButton(page_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_3->addWidget(pushButton);

        stackedWidget->addWidget(page_2);

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(AutorisationDialog);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AutorisationDialog);
    } // setupUi

    void retranslateUi(QDialog *AutorisationDialog)
    {
        AutorisationDialog->setWindowTitle(QApplication::translate("AutorisationDialog", "Dialog", 0));
        PButton_Auth_Begin->setText(QApplication::translate("AutorisationDialog", "Begin new test", 0));
        pushButton_2->setText(QApplication::translate("AutorisationDialog", "PushButton", 0));
        LEdit_Login_Login->setPlaceholderText(QApplication::translate("AutorisationDialog", "Login", 0));
        LEdit_Login_Password->setPlaceholderText(QApplication::translate("AutorisationDialog", "Password", 0));
        pushButton->setText(QApplication::translate("AutorisationDialog", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class AutorisationDialog: public Ui_AutorisationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTORISATIONDIALOG_H
