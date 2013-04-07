/********************************************************************************
** Form generated from reading UI file 'verextenciones.ui'
**
** Created: Thu Apr 4 23:04:50 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VEREXTENCIONES_H
#define UI_VEREXTENCIONES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_VerExtenciones
{
public:
    QListWidget *lstExtenciones;
    QLineEdit *txtExtencion;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *VerExtenciones)
    {
        if (VerExtenciones->objectName().isEmpty())
            VerExtenciones->setObjectName(QString::fromUtf8("VerExtenciones"));
        VerExtenciones->resize(391, 282);
        lstExtenciones = new QListWidget(VerExtenciones);
        lstExtenciones->setObjectName(QString::fromUtf8("lstExtenciones"));
        lstExtenciones->setGeometry(QRect(10, 10, 371, 221));
        txtExtencion = new QLineEdit(VerExtenciones);
        txtExtencion->setObjectName(QString::fromUtf8("txtExtencion"));
        txtExtencion->setGeometry(QRect(10, 240, 113, 25));
        pushButton = new QPushButton(VerExtenciones);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(130, 240, 121, 29));
        pushButton_2 = new QPushButton(VerExtenciones);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(270, 240, 111, 29));

        retranslateUi(VerExtenciones);
        QObject::connect(pushButton, SIGNAL(clicked()), VerExtenciones, SLOT(agregarExtencion()));

        QMetaObject::connectSlotsByName(VerExtenciones);
    } // setupUi

    void retranslateUi(QDialog *VerExtenciones)
    {
        VerExtenciones->setWindowTitle(QApplication::translate("VerExtenciones", "Manejo de Extenciones", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("VerExtenciones", " Agregar ", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("VerExtenciones", " Resetear ", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class VerExtenciones: public Ui_VerExtenciones {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VEREXTENCIONES_H
