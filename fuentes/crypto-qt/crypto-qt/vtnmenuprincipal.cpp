#include "vtnmenuprincipal.h"
#include "ui_vtnmenuprincipal.h"
#include "verextenciones.h"
#include "informacion.h"
#include "ayuda.h"
#include <QPushButton>
#include <QFileDialog>
#include <QButtonGroup>
#include <QAbstractButton>
#include <QMessageBox>

VtnMenuPrincipal::VtnMenuPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VtnMenuPrincipal)
{
    ui->setupUi(this);

    ui->txtSimultaneos->setValidator(new QIntValidator(this));
}

VtnMenuPrincipal::~VtnMenuPrincipal()
{
    delete ui;
}

void VtnMenuPrincipal::abrirInformacion()
{
    Informacion * info;
    info=new Informacion(this);
    info->show();
}

void VtnMenuPrincipal::abrirAyuda()
{
    Ayuda * ayuda;
    ayuda=new Ayuda(this);
    ayuda->showMaximized();
}

void VtnMenuPrincipal::limpiar()
{
    ui->rdbIgnorar->setChecked(false);
    ui->txtSimultaneos->setText("");
    ui->txtPassword->setText("");

    ui->txtDirectorioA->setText("");
    ui->txtDirectorioB->setText("");
    ui->txtDirectorioC->setText("");
    ui->txtDirectorioD->setText("");
    ui->txtDirectorioE->setText("");
    ui->txtDirectorioF->setText("");
}

void VtnMenuPrincipal::seleccionarRuta()
{
    QPushButton * objeto=(QPushButton *)sender();

    QFileDialog::Options opciones=QFileDialog::DontResolveSymlinks | QFileDialog::DontUseNativeDialog;
    QFileDialog * abrir=new QFileDialog(this);

    abrir->setFileMode(QFileDialog::AnyFile);
    abrir->setOptions(opciones);
    abrir->setLabelText(QFileDialog::Accept, "Abrir Archivo");
    abrir->setLabelText(QFileDialog::Reject, "Abrir Directorio");
    abrir->setLabelText(QFileDialog::LookIn, "Buscar en");
    abrir->setLabelText(QFileDialog::FileName, "Nombre del fichero");
    abrir->setLabelText(QFileDialog::FileType, "Tipo del fichero");
    abrir->setWindowTitle("Seleccione el archivo o directorio a trabajar");
    abrir->setDirectory("/home");

    abrir->exec();

    QStringList directorio=abrir->selectedFiles();

    if(objeto==ui->btnDirectorioA)
    {
        if(directorio.isEmpty()==false)
        {
            ui->txtDirectorioA->setText(directorio.at(0));
        }
    }
    else if(objeto==ui->btnDirectorioB)
    {
        if(directorio.isEmpty()==false)
        {
            ui->txtDirectorioB->setText(directorio.at(0));
        }
    }
    else if(objeto==ui->btnDirectorioC)
    {
        if(directorio.isEmpty()==false)
        {
            ui->txtDirectorioC->setText(directorio.at(0));
        }
    }
    else if(objeto==ui->btnDirectorioD)
    {
        if(directorio.isEmpty()==false)
        {
            ui->txtDirectorioD->setText(directorio.at(0));
        }
    }
    else if(objeto==ui->btnDirectorioE)
    {
        if(directorio.isEmpty()==false)
        {
            ui->txtDirectorioE->setText(directorio.at(0));
        }
    }
    else if(objeto==ui->btnDirectorioF)
    {
        if(directorio.isEmpty()==false)
        {
            ui->txtDirectorioF->setText(directorio.at(0));
        }
    }
}
void VtnMenuPrincipal::verExtenciones()
{
    VerExtenciones * extenciones;
    extenciones=new VerExtenciones(this);
    extenciones->show();
}
void VtnMenuPrincipal::ejecutar()
{
    QMessageBox mensaje(this);
    mensaje.setWindowTitle("Error");
    mensaje.setIcon(QMessageBox::Critical);

    if(ui->txtDirectorioA->text().compare("")==0 && ui->txtDirectorioB->text().compare("")==0 &&
            ui->txtDirectorioC->text().compare("")==0 && ui->txtDirectorioD->text().compare("")==0 &&
            ui->txtDirectorioE->text().compare("")==0 && ui->txtDirectorioF->text().compare("")==0)
    {
        mensaje.setText("Debe seleccionar al menos un directorio o archivo a procesar.");
        mensaje.exec();
    }
    else if(ui->txtPassword->text().compare("")==0)
    {
        mensaje.setText("Debe ingresar una contrasea antes de iniciar el proceso.");
        mensaje.exec();
    }
    else
    {
        ui->txtEstado->showMessage("Iniciando proceso ...");

        string strDirectorio[6];
        strDirectorio[0]=ui->txtDirectorioA->text().toStdString();
        strDirectorio[1]=ui->txtDirectorioB->text().toStdString();
        strDirectorio[2]=ui->txtDirectorioC->text().toStdString();
        strDirectorio[3]=ui->txtDirectorioD->text().toStdString();
        strDirectorio[4]=ui->txtDirectorioE->text().toStdString();
        strDirectorio[5]=ui->txtDirectorioF->text().toStdString();

        string strPath="";

        for(int x=0; x<6; x++)
        {
            if(strDirectorio[x].compare("")!=0)
            {
                if(strPath.compare("")!=0)
                {
                    strPath+=":";
                }

                strPath+=strDirectorio[x];
            }
        }

        string strIgnorados=" ";
        if(ui->rdbIgnorar->isChecked()==true)
        {
            strIgnorados="x";
        }

        string strSimultaneo="0";
        if(ui->txtSimultaneos->text().compare("")!=0)
        {
            strSimultaneo=ui->txtSimultaneos->text().toStdString();
        }

        string strPass=ui->txtPassword->text().toStdString();

        QPushButton * objeto=(QPushButton *)sender();

        string strAccion="";
        string strComando="./crypto i";

        if(objeto->objectName().compare("btnEncriptar")==0)
        {
            strAccion="Ejecutando encriptamiento";
            strComando=encriptar(strPath, strPass, strSimultaneo, strIgnorados);
        }
        else
        {
            strAccion="Ejecutando desencriptamiento";
            strComando=desencriptar(strPath, strPass, strSimultaneo, strIgnorados);
        }

        ui->txtEstado->showMessage(tr(strAccion.c_str()));

        try
        {
            system(strComando.c_str());

            ui->txtEstado->showMessage("Proceso Finalizado Exitosamente ...", 2);

            mensaje.setWindowTitle("Operacion Correcta");
            mensaje.setIcon(QMessageBox::Information);
            mensaje.setText("Proceso Finalizado Exitosamente.");
            mensaje.exec();
        }
        catch(...)
        {
            ui->txtEstado->showMessage("Proceso Finalizado Incorrectamente ...", 2);

            mensaje.setText("Proceso Finalizado Incorrectamente.");
            mensaje.exec();
        }
    }
}

string VtnMenuPrincipal::encriptar(string strPath, string strPass, string strSimultaneo, string strIgnorados)
{
    string comando="./crypto l \""+strPath+"\" c "+strPass+" "+strIgnorados+" s "+strSimultaneo+" e";
    return comando;
}
string VtnMenuPrincipal::desencriptar(string strPath, string strPass, string strSimultaneo, string strIgnorados)
{
    string comando="./crypto l \""+strPath+"\" c "+strPass+" "+strIgnorados+" s "+strSimultaneo+" d";
    return comando;
}
