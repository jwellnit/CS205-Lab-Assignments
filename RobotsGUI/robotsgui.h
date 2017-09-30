#ifndef ROBOTSGUI_H
#define ROBOTSGUI_H

#include <QWidget>
#include "../engines/robots.h"

namespace Ui {
class RobotsGUI;
}

class RobotsGUI : public QWidget
{
    Q_OBJECT

public:
    explicit RobotsGUI(QWidget *parent = 0);
    ~RobotsGUI();

    int  get_score();

private slots:
    //respond to button presses
    void on_up_clicked();
    void on_right_clicked();
    void on_left_clicked();
    void on_down_clicked();
    void on_upLeft_clicked();
    void on_upRight_clicked();
    void on_downLeft_clicked();
    void on_downRight_clicked();
    void on_wait_clicked();
    void on_waitSafe_clicked();
    void on_skip_clicked();
    void on_teleport_clicked();
    void on_redraw_clicked();
    void on_quit_clicked();
    void on_yes_clicked();
    void on_no_clicked();

private:
    void set_up(int rows, int cols, int startEnemies); //start a new game
    void print(); //print the board
    void play_again(); //prompt the user to play again

    Ui::RobotsGUI *ui;
    Robots *r;
    int numEnemies;
};

#endif // ROBOTSGUI_H
