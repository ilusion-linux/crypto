#include <QApplication>
#include <QRect>
#include <QDesktopWidget>
#include <QStyleFactory>
#include "mainwindow.h"
#include <stdio.h>
#include <iostream>

using std::cout;

main(int argc, char *argv[])
{
    QApplication::setStyle("Plastique");

    for(int x=0; x<QStyleFactory::keys().count(); x++)
    {
        cout<<QStyleFactory::keys().takeAt(x).toStdString()<<"\n";//"Hola";//QStyleFactory::keys().value(x, "---");
    }

    QApplication a(argc, argv);

    MainWindow menuPrincipal;

    int ancho=menuPrincipal.geometry().width()/2;
    int alto=menuPrincipal.geometry().height()/2;

    QDesktopWidget * desktop=QApplication::desktop();
    QRect pantalla=desktop->screenGeometry();

    int px=(pantalla.width()/2)-(ancho);
    int py=(pantalla.height()/2)-(alto);

    menuPrincipal.move(QPoint(px,py));
    menuPrincipal.show();

    return a.exec();
}
