#include "verextenciones.h"
#include "ui_verextenciones.h"
#include <QErrorMessage>
#include <QMessageBox>

VerExtenciones::VerExtenciones(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VerExtenciones)
{
    ui->setupUi(this);

    cargarExtenciones();
}

VerExtenciones::~VerExtenciones()
{
    delete ui;
}

void VerExtenciones::cargarExtenciones()
{
    extenciones.leerIgnorados();

    ignorados=(struct ignorar *)extenciones.darIgnorados();

    while(ignorados!=NULL)
    {
        ui->lstExtenciones->addItem(ignorados->extension.c_str());

        ignorados=ignorados->siguiente;
    }
}

void VerExtenciones::agregarExtencion()
{
    if(ui->txtExtencion->text().compare("")!=0)
    {
        char * exten=new char[ui->txtExtencion->text().length()+1];
        strcpy(exten, ui->txtExtencion->text().toStdString().c_str());
        extenciones.agregarIgnorados(exten);

        ui->lstExtenciones->clear();
        cargarExtenciones();

        ui->txtExtencion->setText("");
    }
    else
    {
        QMessageBox mensaje(this);
        mensaje.setWindowTitle("Error");
        mensaje.setText("Ingrese la extencion que desea agregar.");
        mensaje.setIcon(QMessageBox::Critical);
        mensaje.exec();
    }
}

void VerExtenciones::reiniciar()
{
    extenciones.reiniciarIgnorados();

    ui->lstExtenciones->clear();
}
