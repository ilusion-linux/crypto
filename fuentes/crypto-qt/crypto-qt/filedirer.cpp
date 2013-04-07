#include "filedirer.h"

void FileDirer::accept()
{
    QStringList files = selectedFiles();

    if (files.isEmpty())
        return;

    emit filesSelected(files);

    QDialog::accept();
}
