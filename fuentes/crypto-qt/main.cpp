#include <QApplication>
#include <QRect>
#include <QDesktopWidget>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
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