#ifndef FORM_H
#define FORM_H

#include <QWidget>

#include "shareddata.h"
#include "multithreadserver.h"

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();

private slots:
    void modifyParams();

private:
    Ui::Form *ui;

    SharedData sharedData;
    MultiThreadServer server;
};

#endif // FORM_H
