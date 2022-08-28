#include "guanyu.h"
#include "ui_guanyu.h"

guanyu::guanyu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::guanyu)
{
    ui->setupUi(this);
}

guanyu::~guanyu()
{
    delete ui;
}
