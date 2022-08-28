#include "caozuo.h"
#include "ui_caozuo.h"

caozuo::caozuo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::caozuo)
{
    ui->setupUi(this);
}

caozuo::~caozuo()
{
    delete ui;
}
