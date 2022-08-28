#ifndef CAOZUO_H
#define CAOZUO_H

#include <QMainWindow>

namespace Ui {
class caozuo;
}

class caozuo : public QMainWindow
{
    Q_OBJECT

public:
    explicit caozuo(QWidget *parent = nullptr);
    ~caozuo();

private:
    Ui::caozuo *ui;
};

#endif // CAOZUO_H
