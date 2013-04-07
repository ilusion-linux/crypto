#ifndef VTNMENUPRINCIPAL_H
#define VTNMENUPRINCIPAL_H

#include <QMainWindow>
#include <cstring>

using std::string;

namespace Ui {
class VtnMenuPrincipal;
}

class VtnMenuPrincipal : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit VtnMenuPrincipal(QWidget *parent = 0);
    ~VtnMenuPrincipal();

private slots:
    void abrirInformacion();
    void seleccionarRuta();
    void verExtenciones();
    void ejecutar();
    void abrirAyuda();

private:
    Ui::VtnMenuPrincipal *ui;
    string encriptar(string, string, string, string);
    string desencriptar(string, string, string, string);
};

#endif // VTNMENUPRINCIPAL_H
