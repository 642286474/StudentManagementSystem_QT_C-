#include "shezhi.h"
#include "ui_shezhi.h"

shezhi::shezhi(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::shezhi)
{
    ui->setupUi(this);
}

shezhi::~shezhi()
{
    delete ui;
}
