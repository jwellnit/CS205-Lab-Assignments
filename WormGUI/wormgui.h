#ifndef WORMGUI_H
#define WORMGUI_H

#include <QWidget>
#include "../engines/worm.h"

namespace Ui {
class WormGUI;
}

class WormGUI : public QWidget
{
    Q_OBJECT

public:
    explicit WormGUI(QWidget *parent = 0);
    ~WormGUI();

    int get_score();

private slots:
    //respond to button presses
    //ADD YOURS HERE

    void on_w_button_clicked();

    void on_s_button_clicked();

    void on_quit_button_clicked();

    void on_n_button_clicked();

    void on_e_button_clicked();

    void on_yes_clicked();

    void on_no_clicked();

private:
    void set_up(int rows, int cols); //start a new game
    void print(); //print the board
    void play_again(); //prompt the user to play again

    bool continueGame;

    Ui::WormGUI *ui;
    Worm *worm;
};


#endif // WORMGUI.H
