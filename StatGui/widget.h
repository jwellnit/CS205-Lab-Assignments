#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "../Zebra/playergamehistory.h"
#include "../Zebra/player.h"
#include "../Zebra/game.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0, PlayerGameHistory* pgh = nullptr, Player* pl = nullptr);
    ~Widget();

    Player *p;
    PlayerGameHistory *ph;

private slots:
    void on_pushButton_clicked();

private:
    void calc_stats();

    Ui::Widget *ui;
};

#endif // WIDGET_H
