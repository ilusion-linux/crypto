/********************************************************************************
** Form generated from reading UI file 'vtnmenuprincipal.ui'
**
** Created: Sun Apr 7 17:11:15 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VTNMENUPRINCIPAL_H
#define UI_VTNMENUPRINCIPAL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VtnMenuPrincipal
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QGroupBox *groupBox;
    QRadioButton *rdbIgnorar;
    QPushButton *btnExtenciones;
    QLabel *label_2;
    QLineEdit *txtSimultaneos;
    QGroupBox *groupBox_2;
    QLineEdit *txtDirectorioA;
    QLineEdit *txtDirectorioF;
    QLineEdit *txtDirectorioE;
    QLineEdit *txtDirectorioD;
    QLineEdit *txtDirectorioC;
    QLineEdit *txtDirectorioB;
    QPushButton *btnDirectorioA;
    QPushButton *btnDirectorioB;
    QPushButton *btnDirectorioC;
    QPushButton *btnDirectorioD;
    QPushButton *btnDirectorioE;
    QPushButton *btnDirectorioF;
    QLabel *label_3;
    QLineEdit *txtPassword;
    QPushButton *btnEncriptar;
    QPushButton *btnDesencriptar;
    QPushButton *btnInformacion;
    QPushButton *btnInformacion_2;
    QStatusBar *txtEstado;

    void setupUi(QMainWindow *VtnMenuPrincipal)
    {
        if (VtnMenuPrincipal->objectName().isEmpty())
            VtnMenuPrincipal->setObjectName(QString::fromUtf8("VtnMenuPrincipal"));
        VtnMenuPrincipal->setWindowModality(Qt::NonModal);
        VtnMenuPrincipal->resize(590, 427);
        VtnMenuPrincipal->setDocumentMode(false);
        centralWidget = new QWidget(VtnMenuPrincipal);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 261, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Comic Sans MS"));
        font.setPointSize(24);
        label->setFont(font);
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 50, 391, 91));
        rdbIgnorar = new QRadioButton(groupBox);
        rdbIgnorar->setObjectName(QString::fromUtf8("rdbIgnorar"));
        rdbIgnorar->setGeometry(QRect(20, 23, 171, 25));
        QFont font1;
        font1.setPointSize(11);
        rdbIgnorar->setFont(font1);
        btnExtenciones = new QPushButton(groupBox);
        btnExtenciones->setObjectName(QString::fromUtf8("btnExtenciones"));
        btnExtenciones->setGeometry(QRect(20, 53, 161, 29));
        btnExtenciones->setFont(font1);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(220, 23, 171, 19));
        label_2->setFont(font1);
        txtSimultaneos = new QLineEdit(groupBox);
        txtSimultaneos->setObjectName(QString::fromUtf8("txtSimultaneos"));
        txtSimultaneos->setGeometry(QRect(220, 53, 113, 25));
        txtSimultaneos->setFont(font1);
        txtSimultaneos->setInputMethodHints(Qt::ImhNone);
        txtSimultaneos->setEchoMode(QLineEdit::Normal);
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 150, 561, 211));
        txtDirectorioA = new QLineEdit(groupBox_2);
        txtDirectorioA->setObjectName(QString::fromUtf8("txtDirectorioA"));
        txtDirectorioA->setGeometry(QRect(10, 20, 511, 25));
        txtDirectorioA->setReadOnly(true);
        txtDirectorioF = new QLineEdit(groupBox_2);
        txtDirectorioF->setObjectName(QString::fromUtf8("txtDirectorioF"));
        txtDirectorioF->setGeometry(QRect(10, 170, 511, 25));
        txtDirectorioF->setReadOnly(true);
        txtDirectorioE = new QLineEdit(groupBox_2);
        txtDirectorioE->setObjectName(QString::fromUtf8("txtDirectorioE"));
        txtDirectorioE->setGeometry(QRect(10, 140, 511, 25));
        txtDirectorioE->setReadOnly(true);
        txtDirectorioD = new QLineEdit(groupBox_2);
        txtDirectorioD->setObjectName(QString::fromUtf8("txtDirectorioD"));
        txtDirectorioD->setGeometry(QRect(10, 110, 511, 25));
        txtDirectorioD->setReadOnly(true);
        txtDirectorioC = new QLineEdit(groupBox_2);
        txtDirectorioC->setObjectName(QString::fromUtf8("txtDirectorioC"));
        txtDirectorioC->setGeometry(QRect(10, 80, 511, 25));
        txtDirectorioC->setReadOnly(true);
        txtDirectorioB = new QLineEdit(groupBox_2);
        txtDirectorioB->setObjectName(QString::fromUtf8("txtDirectorioB"));
        txtDirectorioB->setGeometry(QRect(10, 50, 511, 25));
        txtDirectorioB->setReadOnly(true);
        btnDirectorioA = new QPushButton(groupBox_2);
        btnDirectorioA->setObjectName(QString::fromUtf8("btnDirectorioA"));
        btnDirectorioA->setGeometry(QRect(530, 20, 21, 29));
        btnDirectorioA->setFont(font1);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imagenes/Directory2.png"), QSize(), QIcon::Normal, QIcon::On);
        btnDirectorioA->setIcon(icon);
        btnDirectorioB = new QPushButton(groupBox_2);
        btnDirectorioB->setObjectName(QString::fromUtf8("btnDirectorioB"));
        btnDirectorioB->setGeometry(QRect(530, 50, 21, 29));
        btnDirectorioB->setFont(font1);
        btnDirectorioB->setIcon(icon);
        btnDirectorioC = new QPushButton(groupBox_2);
        btnDirectorioC->setObjectName(QString::fromUtf8("btnDirectorioC"));
        btnDirectorioC->setGeometry(QRect(530, 80, 21, 29));
        btnDirectorioC->setFont(font1);
        btnDirectorioC->setIcon(icon);
        btnDirectorioD = new QPushButton(groupBox_2);
        btnDirectorioD->setObjectName(QString::fromUtf8("btnDirectorioD"));
        btnDirectorioD->setGeometry(QRect(530, 110, 21, 29));
        btnDirectorioD->setFont(font1);
        btnDirectorioD->setIcon(icon);
        btnDirectorioE = new QPushButton(groupBox_2);
        btnDirectorioE->setObjectName(QString::fromUtf8("btnDirectorioE"));
        btnDirectorioE->setGeometry(QRect(530, 140, 21, 29));
        btnDirectorioE->setFont(font1);
        btnDirectorioE->setIcon(icon);
        btnDirectorioF = new QPushButton(groupBox_2);
        btnDirectorioF->setObjectName(QString::fromUtf8("btnDirectorioF"));
        btnDirectorioF->setGeometry(QRect(530, 170, 21, 29));
        btnDirectorioF->setFont(font1);
        btnDirectorioF->setIcon(icon);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 375, 101, 19));
        txtPassword = new QLineEdit(centralWidget);
        txtPassword->setObjectName(QString::fromUtf8("txtPassword"));
        txtPassword->setGeometry(QRect(120, 370, 211, 25));
        txtPassword->setEchoMode(QLineEdit::Password);
        btnEncriptar = new QPushButton(centralWidget);
        btnEncriptar->setObjectName(QString::fromUtf8("btnEncriptar"));
        btnEncriptar->setGeometry(QRect(340, 370, 102, 29));
        btnDesencriptar = new QPushButton(centralWidget);
        btnDesencriptar->setObjectName(QString::fromUtf8("btnDesencriptar"));
        btnDesencriptar->setGeometry(QRect(451, 370, 131, 29));
        btnInformacion = new QPushButton(centralWidget);
        btnInformacion->setObjectName(QString::fromUtf8("btnInformacion"));
        btnInformacion->setGeometry(QRect(550, 120, 31, 31));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/imagenes/informacion.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/imagenes/informacion.png"), QSize(), QIcon::Normal, QIcon::On);
        icon1.addFile(QString::fromUtf8(":/imagenes/informacion.png"), QSize(), QIcon::Active, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/imagenes/informacion.png"), QSize(), QIcon::Active, QIcon::On);
        icon1.addFile(QString::fromUtf8(":/imagenes/informacion.png"), QSize(), QIcon::Selected, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/imagenes/informacion.png"), QSize(), QIcon::Selected, QIcon::On);
        btnInformacion->setIcon(icon1);
        btnInformacion->setIconSize(QSize(32, 32));
        btnInformacion->setFlat(false);
        btnInformacion_2 = new QPushButton(centralWidget);
        btnInformacion_2->setObjectName(QString::fromUtf8("btnInformacion_2"));
        btnInformacion_2->setGeometry(QRect(510, 120, 31, 31));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/imagenes/ayuda.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnInformacion_2->setIcon(icon2);
        btnInformacion_2->setIconSize(QSize(32, 32));
        btnInformacion_2->setFlat(false);
        VtnMenuPrincipal->setCentralWidget(centralWidget);
        txtEstado = new QStatusBar(VtnMenuPrincipal);
        txtEstado->setObjectName(QString::fromUtf8("txtEstado"));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        QBrush brush2(QColor(127, 127, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush2);
        QBrush brush3(QColor(170, 170, 170, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        QBrush brush4(QColor(255, 255, 220, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        txtEstado->setPalette(palette);
        txtEstado->setCursor(QCursor(Qt::ArrowCursor));
        txtEstado->setAutoFillBackground(true);
        VtnMenuPrincipal->setStatusBar(txtEstado);
#ifndef QT_NO_SHORTCUT
        label_2->setBuddy(txtSimultaneos);
#endif // QT_NO_SHORTCUT

        retranslateUi(VtnMenuPrincipal);
        QObject::connect(btnInformacion, SIGNAL(clicked()), VtnMenuPrincipal, SLOT(abrirInformacion()));
        QObject::connect(btnDirectorioA, SIGNAL(clicked()), VtnMenuPrincipal, SLOT(seleccionarRuta()));
        QObject::connect(btnDirectorioB, SIGNAL(clicked()), VtnMenuPrincipal, SLOT(seleccionarRuta()));
        QObject::connect(btnDirectorioC, SIGNAL(clicked()), VtnMenuPrincipal, SLOT(seleccionarRuta()));
        QObject::connect(btnDirectorioD, SIGNAL(clicked()), VtnMenuPrincipal, SLOT(seleccionarRuta()));
        QObject::connect(btnDirectorioE, SIGNAL(clicked()), VtnMenuPrincipal, SLOT(seleccionarRuta()));
        QObject::connect(btnDirectorioF, SIGNAL(clicked()), VtnMenuPrincipal, SLOT(seleccionarRuta()));
        QObject::connect(btnExtenciones, SIGNAL(clicked()), VtnMenuPrincipal, SLOT(verExtenciones()));
        QObject::connect(btnEncriptar, SIGNAL(clicked()), VtnMenuPrincipal, SLOT(ejecutar()));
        QObject::connect(btnDesencriptar, SIGNAL(clicked()), VtnMenuPrincipal, SLOT(ejecutar()));
        QObject::connect(btnInformacion_2, SIGNAL(clicked()), VtnMenuPrincipal, SLOT(abrirAyuda()));

        QMetaObject::connectSlotsByName(VtnMenuPrincipal);
    } // setupUi

    void retranslateUi(QMainWindow *VtnMenuPrincipal)
    {
        VtnMenuPrincipal->setWindowTitle(QApplication::translate("VtnMenuPrincipal", "Crypto-qt     0.05", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("VtnMenuPrincipal", "  Crypto 0.05", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("VtnMenuPrincipal", "Opciones", 0, QApplication::UnicodeUTF8));
        rdbIgnorar->setText(QApplication::translate("VtnMenuPrincipal", "Ignorar extenciones", 0, QApplication::UnicodeUTF8));
        btnExtenciones->setText(QApplication::translate("VtnMenuPrincipal", "Extenciones", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("VtnMenuPrincipal", "Trabajos Simultaneos", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("VtnMenuPrincipal", "Directorios de trabajo", 0, QApplication::UnicodeUTF8));
        btnDirectorioA->setText(QString());
        btnDirectorioB->setText(QString());
        btnDirectorioC->setText(QString());
        btnDirectorioD->setText(QString());
        btnDirectorioE->setText(QString());
        btnDirectorioF->setText(QString());
        label_3->setText(QApplication::translate("VtnMenuPrincipal", "Contrase\303\261a", 0, QApplication::UnicodeUTF8));
        btnEncriptar->setText(QApplication::translate("VtnMenuPrincipal", "Encriptar", 0, QApplication::UnicodeUTF8));
        btnDesencriptar->setText(QApplication::translate("VtnMenuPrincipal", "Desencriptar", 0, QApplication::UnicodeUTF8));
        btnInformacion->setText(QString());
        btnInformacion_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class VtnMenuPrincipal: public Ui_VtnMenuPrincipal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VTNMENUPRINCIPAL_H
