#include "vtnmenuprincipal.h"
#include "ui_vtnmenuprincipal.h"

VtnMenuPrincipal::VtnMenuPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VtnMenuPrincipal)
{
    ui->setupUi(this);
}

VtnMenuPrincipal::~VtnMenuPrincipal()
{
    delete ui;
}
