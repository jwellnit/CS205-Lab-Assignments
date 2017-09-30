#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include "../Zebra/game.h"
#include "../Zebra/gamehistory.h"
#include "../Zebra/player.h"
#include "../Zebra/playergamehistory.h"
#include "../tui/robotstui.h"
#include "../tui/wormtui.h"
#include "../ConsoleGUI/mainwindow.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0, PlayerGameHistory* pgh = nullptr);
    ~Widget();

    Player* get_current_player();
    void close_this();
    Player* currentPlayer;

private slots:
    void on_playerList_clicked(const QModelIndex &index);
    void on_okayButton_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
