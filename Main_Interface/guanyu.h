#ifndef GUANYU_H
#define GUANYU_H

#include <QMainWindow>

namespace Ui {
class guanyu;
}

class guanyu : public QMainWindow
{
    Q_OBJECT

public:
    explicit guanyu(QWidget *parent = nullptr);
    ~guanyu();

private:
    Ui::guanyu *ui;
};

#endif // GUANYU_H
