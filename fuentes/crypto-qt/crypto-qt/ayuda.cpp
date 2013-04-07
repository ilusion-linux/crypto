#include "ayuda.h"
#include "ui_ayuda.h"

Ayuda::Ayuda(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ayuda)
{
    ui->setupUi(this);
}

Ayuda::~Ayuda()
{
    delete ui;
}
