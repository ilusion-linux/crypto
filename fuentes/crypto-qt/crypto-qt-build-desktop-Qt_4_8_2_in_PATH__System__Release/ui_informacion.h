/********************************************************************************
** Form generated from reading UI file 'informacion.ui'
**
** Created: Mon Apr 8 15:12:32 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFORMACION_H
#define UI_INFORMACION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Informacion
{
public:
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QLabel *label_4;
    QWidget *tab;
    QPlainTextEdit *plainTextEdit;
    QWidget *tab_2;
    QPlainTextEdit *plainTextEdit_2;
    QLabel *label;
    QWidget *tab_4;
    QPlainTextEdit *plainTextEdit_3;

    void setupUi(QDialog *Informacion)
    {
        if (Informacion->objectName().isEmpty())
            Informacion->setObjectName(QString::fromUtf8("Informacion"));
        Informacion->resize(441, 325);
        tabWidget = new QTabWidget(Informacion);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 441, 325));
        tabWidget->setTabPosition(QTabWidget::North);
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        label_4 = new QLabel(tab_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(-1, 0, 440, 298));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/logo.png")));
        label_4->setScaledContents(true);
        tabWidget->addTab(tab_3, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        plainTextEdit = new QPlainTextEdit(tab);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(0, 0, 441, 301));
        plainTextEdit->setAutoFillBackground(false);
        plainTextEdit->setLineWrapMode(QPlainTextEdit::WidgetWidth);
        plainTextEdit->setReadOnly(true);
        plainTextEdit->setTextInteractionFlags(Qt::TextSelectableByMouse);
        plainTextEdit->setBackgroundVisible(false);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        plainTextEdit_2 = new QPlainTextEdit(tab_2);
        plainTextEdit_2->setObjectName(QString::fromUtf8("plainTextEdit_2"));
        plainTextEdit_2->setGeometry(QRect(0, 0, 441, 231));
        plainTextEdit_2->setAutoFillBackground(false);
        plainTextEdit_2->setReadOnly(true);
        plainTextEdit_2->setTextInteractionFlags(Qt::TextSelectableByMouse);
        plainTextEdit_2->setBackgroundVisible(false);
        label = new QLabel(tab_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 240, 411, 51));
        label->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/gpl.png")));
        label->setAlignment(Qt::AlignCenter);
        tabWidget->addTab(tab_2, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        plainTextEdit_3 = new QPlainTextEdit(tab_4);
        plainTextEdit_3->setObjectName(QString::fromUtf8("plainTextEdit_3"));
        plainTextEdit_3->setGeometry(QRect(0, 0, 441, 301));
        plainTextEdit_3->setAutoFillBackground(false);
        plainTextEdit_3->setLineWrapMode(QPlainTextEdit::WidgetWidth);
        plainTextEdit_3->setReadOnly(true);
        plainTextEdit_3->setTextInteractionFlags(Qt::TextSelectableByMouse);
        plainTextEdit_3->setBackgroundVisible(false);
        tabWidget->addTab(tab_4, QString());

        retranslateUi(Informacion);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Informacion);
    } // setupUi

    void retranslateUi(QDialog *Informacion)
    {
        Informacion->setWindowTitle(QApplication::translate("Informacion", "Crypto 0.05", 0, QApplication::UnicodeUTF8));
        label_4->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("Informacion", "Logo", 0, QApplication::UnicodeUTF8));
        plainTextEdit->setPlainText(QApplication::translate("Informacion", "Este software es para encriptacion de cualquier tipo de archivo multimedia, basando en una contrase\303\261a ingresada por el usuario.\n"
"\n"
"Este software es creado para la comunidad lug de Zacapa Guatemala, y el resto de personas que deseen utilizarlo.\n"
"\n"
"Para el desarrollo de este sistema se utilizo el lenguaje C++ y manejo de threads con la libreria Pthread que cumple con los standares de portabilidad POSIX.  La interfaz grafica fue desarrollado con el framework QT.", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Informacion", "Acerca De", 0, QApplication::UnicodeUTF8));
        plainTextEdit_2->setPlainText(QApplication::translate("Informacion", "Crypto is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 3 of the License, or (at your option) any later version.\n"
"\n"
"Crypto is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.\n"
"\n"
"You should have received a copy of the GNU General Public License along with GIMP.  If not, see <http://www.gnu.org/licenses/>.", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Informacion", "Licencia", 0, QApplication::UnicodeUTF8));
        plainTextEdit_3->setPlainText(QApplication::translate("Informacion", "Este programa fue escrito por Luis Alfredo Morales Franco, conocido en la web como ilusion-linux.\n"
"\n"
"Para contactar con el autor puedes escribir a los corres ilusion.linux@gmail.com y a ghots.recon@hotmail.com\n"
"\n"
"O puedes visitar el sitio web http://www.zacapalug.org o http://ilusion-linux.com\n"
"\n"
"El logo del sistema tambien fue creado con software libre.", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("Informacion", "Autor", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Informacion: public Ui_Informacion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFORMACION_H
