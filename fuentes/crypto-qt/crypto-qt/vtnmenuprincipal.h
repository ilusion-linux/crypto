#ifndef VTNMENUPRINCIPAL_H
#define VTNMENUPRINCIPAL_H

#include <QMainWindow>

namespace Ui {
class VtnMenuPrincipal;
}

class VtnMenuPrincipal : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit VtnMenuPrincipal(QWidget *parent = 0);
    ~VtnMenuPrincipal();
    
private:
    Ui::VtnMenuPrincipal *ui;
};

#endif // VTNMENUPRINCIPAL_H
