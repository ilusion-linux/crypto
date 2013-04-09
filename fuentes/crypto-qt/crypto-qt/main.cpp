#include <QApplication>
#include <QRect>
#include <QDesktopWidget>
#include "vtnmenuprincipal.h"
#include <iostream>
#include <cstring>

using std::cout;
using std::cin;
using std::string;
using std::endl;

int main(int argc, char *argv[])
{
    int expresion;

    cout<<"Ingrese expresion: ";
    //getline(cin, expresion);
    cin>>expresion;

    cout<<"------------------ "<<expresion<<"  "<<endl<<endl;

    /*for(int x=0; x<expresion.length(); x++)
    {
        cout<<expresion[x]<<endl;
    }*/


    QApplication::setStyle("Plastique");

    QApplication a(argc, argv);
    VtnMenuPrincipal menuPrincipal;

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
