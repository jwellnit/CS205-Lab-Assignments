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

    //instance vars
    QString firstName;
    QString lastName;
    QString address;

    PlayerGameHistory* pgh;
    Player* p;
    Player* currentPlayer;

private slots:
    void on_okayButton_clicked();

    void on_firstNameLine_textChanged(const QString &arg1);
    Player* get_current_player();
    void close_this();    }

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
