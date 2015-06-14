/********************************************************************************
** Form generated from reading UI file 'rootform.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROOTFORM_H
#define UI_ROOTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RootForm
{
public:
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_6;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *ComboBox_Config_Profession;
    QComboBox *ComboBox_Config_Course;
    QLabel *label_2;
    QComboBox *ComboBox_Config_Lesson;
    QLabel *label_3;
    QComboBox *ComboBox_Config_Theme;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout;
    QSlider *horizontalSlider;
    QSpinBox *spinBox;
    QLabel *label_5;
    QSpinBox *spinBox_2;
    QWidget *page_2;

    void setupUi(QWidget *RootForm)
    {
        if (RootForm->objectName().isEmpty())
            RootForm->setObjectName(QStringLiteral("RootForm"));
        RootForm->resize(663, 430);
        verticalLayout = new QVBoxLayout(RootForm);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        stackedWidget = new QStackedWidget(RootForm);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        verticalLayout_2 = new QVBoxLayout(page);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_6 = new QLabel(page);
        label_6->setObjectName(QStringLiteral("label_6"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/resources/logo.png")));
        label_6->setScaledContents(false);
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_6);

        groupBox = new QGroupBox(page);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        ComboBox_Config_Profession = new QComboBox(groupBox);
        ComboBox_Config_Profession->setObjectName(QStringLiteral("ComboBox_Config_Profession"));

        horizontalLayout_2->addWidget(ComboBox_Config_Profession);

        ComboBox_Config_Course = new QComboBox(groupBox);
        ComboBox_Config_Course->setObjectName(QStringLiteral("ComboBox_Config_Course"));
        ComboBox_Config_Course->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_2->addWidget(ComboBox_Config_Course);


        formLayout->setLayout(0, QFormLayout::FieldRole, horizontalLayout_2);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        ComboBox_Config_Lesson = new QComboBox(groupBox);
        ComboBox_Config_Lesson->setObjectName(QStringLiteral("ComboBox_Config_Lesson"));
        ComboBox_Config_Lesson->setEnabled(false);

        formLayout->setWidget(1, QFormLayout::FieldRole, ComboBox_Config_Lesson);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        ComboBox_Config_Theme = new QComboBox(groupBox);
        ComboBox_Config_Theme->setObjectName(QStringLiteral("ComboBox_Config_Theme"));
        ComboBox_Config_Theme->setEnabled(false);

        formLayout->setWidget(2, QFormLayout::FieldRole, ComboBox_Config_Theme);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSlider = new QSlider(groupBox);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalSlider);

        spinBox = new QSpinBox(groupBox);
        spinBox->setObjectName(QStringLiteral("spinBox"));

        horizontalLayout->addWidget(spinBox);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout->addWidget(label_5);

        spinBox_2 = new QSpinBox(groupBox);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setReadOnly(true);
        spinBox_2->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_2->setAccelerated(false);

        horizontalLayout->addWidget(spinBox_2);


        formLayout->setLayout(3, QFormLayout::FieldRole, horizontalLayout);


        verticalLayout_2->addWidget(groupBox);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        stackedWidget->addWidget(page_2);

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(RootForm);

        QMetaObject::connectSlotsByName(RootForm);
    } // setupUi

    void retranslateUi(QWidget *RootForm)
    {
        RootForm->setWindowTitle(QApplication::translate("RootForm", "Form", 0));
        label_6->setText(QString());
        groupBox->setTitle(QApplication::translate("RootForm", "Test connfiguration", 0));
        label->setText(QApplication::translate("RootForm", "Profession:", 0));
        ComboBox_Config_Course->clear();
        ComboBox_Config_Course->insertItems(0, QStringList()
         << QApplication::translate("RootForm", "Course 1", 0)
         << QApplication::translate("RootForm", "Course 2", 0)
         << QApplication::translate("RootForm", "Course 3", 0)
         << QApplication::translate("RootForm", "Course 4", 0)
        );
        label_2->setText(QApplication::translate("RootForm", "Lesson:", 0));
        label_3->setText(QApplication::translate("RootForm", "Theme:", 0));
        label_4->setText(QApplication::translate("RootForm", "Questions count:", 0));
        label_5->setText(QApplication::translate("RootForm", "/", 0));
    } // retranslateUi

};

namespace Ui {
    class RootForm: public Ui_RootForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOTFORM_H
