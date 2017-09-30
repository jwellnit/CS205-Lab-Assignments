#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "../Zebra/player.h"
#include "../Zebra/playergamehistory.h"
#include "../Zebra/game.h"
#include "../Zebra/gamehistory.h"
#include "../Zebra/dbtool.h"
#include "../Zebra/dbtable.h"
#include "../Zebra/baseclass.h"

#include "../RobotsGUI/robotsgui.h"
#include "../RobotsGUI/robotsgui.ui"

#include "../WormGUI/wormgui.h"
#include "../WormGUI/wormgui.ui"

#include "../engines/robots.h"
#include "../engines/worm.h"

#include "../ExistingPlayerGui/widget.h"
#include "../ExistingPlayerGui/widget.ui"

#include "../NewPlayerGui/widget.h"
#include "../NewPlayerGui/widget.ui"

#include "../StatGui/widget.h"
#include "../StatGui/widget.ui"

#include "../TopThreeGamesGui/widget.h"
#include "../TopThreeGamesGui/widget.ui"

#include "../TopThreePlayersGui/widget.h"
#include "../TopThreePlayersGui/widget.ui"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //instance vars
    Player* currentPlayer;
    PlayerGameHistory* pgh;
    DBTool* dbTool;


private slots:
    void on_playRobotsButton_clicked();
    void on_playWormButton_clicked();
    void on_actionExit_Program_triggered();
    void on_actionNew_Player_triggered();
    void on_actionTop_3_Players_triggered();
    void on_actionSelect_Existing_Player_triggered();
    void on_actionCalculated_Statistics_triggered();
    void on_actionTop_3_Games_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
