/********************************************************************************
** Form generated from reading UI file 'verignorados.ui'
**
** Created: Tue Apr 2 18:51:40 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VERIGNORADOS_H
#define UI_VERIGNORADOS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_verignorados
{
public:
    QDialogButtonBox *buttonBox;
    QListWidget *listWidget;

    void setupUi(QDialog *verignorados)
    {
        if (verignorados->objectName().isEmpty())
            verignorados->setObjectName(QString::fromUtf8("verignorados"));
        verignorados->resize(338, 251);
        buttonBox = new QDialogButtonBox(verignorados);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(160, 210, 171, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        listWidget = new QListWidget(verignorados);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(10, 10, 321, 192));

        retranslateUi(verignorados);
        QObject::connect(buttonBox, SIGNAL(accepted()), verignorados, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), verignorados, SLOT(reject()));

        QMetaObject::connectSlotsByName(verignorados);
    } // setupUi

    void retranslateUi(QDialog *verignorados)
    {
        verignorados->setWindowTitle(QApplication::translate("verignorados", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class verignorados: public Ui_verignorados {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VERIGNORADOS_H
