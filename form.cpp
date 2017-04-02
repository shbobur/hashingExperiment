#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

    modifyParams();

    connect(ui->hashTypeComboBox,   SIGNAL(currentIndexChanged(int)),   this,   SLOT(modifyParams()));
    connect(ui->opsNumSpinBox,      SIGNAL(valueChanged(int)),          this,   SLOT(modifyParams()));

    server.startListening();
}

Form::~Form()
{
    delete ui;
}

void Form::modifyParams()
{
    sharedData.setHashType(ui->hashTypeComboBox->currentIndex());
    sharedData.setNumOfHashingOps(ui->opsNumSpinBox->value());
}
