#ifndef FILEDIRER_H
#define FILEDIRER_H

#include <QFileDialog>

class FileDirer: public QFileDialog
{
public:
    FileDirer(QWidget * parent, Qt::WindowFlags flags ):
        QFileDialog(parent,flags) {}

    FileDirer(QWidget * par=0, const QString & cap=QString(), const QString & dir=QString(), const QString & fil=QString()):
        QFileDialog(par,cap,dir,fil) {}

public slots:
    void accept();
};
#endif // FILEDIRER_H
