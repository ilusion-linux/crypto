#ifndef AYUDA_H
#define AYUDA_H

#include <QDialog>

namespace Ui {
class Ayuda;
}

class Ayuda : public QDialog
{
    Q_OBJECT
    
public:
    explicit Ayuda(QWidget *parent = 0);
    ~Ayuda();
    
private:
    Ui::Ayuda *ui;
};

#endif // AYUDA_H
