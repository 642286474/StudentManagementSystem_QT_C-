#ifndef SHEZHI_H
#define SHEZHI_H

#include <QMainWindow>

namespace Ui {
class shezhi;
}

class shezhi : public QMainWindow
{
    Q_OBJECT

public:
    explicit shezhi(QWidget *parent = nullptr);
    ~shezhi();

private:
    Ui::shezhi *ui;
};

#endif // SHEZHI_H
