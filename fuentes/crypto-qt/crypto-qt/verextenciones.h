#ifndef VEREXTENCIONES_H
#define VEREXTENCIONES_H

#include <QDialog>
#include "/home/ilusion-linux/Documents/Proyectos/crypto/fuentes/buscador.h"

namespace Ui {
class VerExtenciones;
}

class VerExtenciones : public QDialog
{
    Q_OBJECT
    
public:
    explicit VerExtenciones(QWidget *parent = 0);
    ~VerExtenciones();
    
private slots:
    void agregarExtencion();
    void reiniciar();

private:
    Buscador extenciones;
    Ui::VerExtenciones *ui;

    struct ignorar
    {
        string extension;
        struct ignorar * siguiente;
    };
    struct ignorar * ignorados;

    void cargarExtenciones();
};

#endif // VEREXTENCIONES_H
