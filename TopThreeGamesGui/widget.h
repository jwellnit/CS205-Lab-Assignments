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

    PlayerGameHistory *ph;
    vector<Game*>      g;

    Game *g1;
    Game *g2;
    Game *g3;

private slots:
    void on_pushButton_clicked();

private:
    void calc_winners();

    Ui::Widget *ui;
};

#endif // WIDGET_H
