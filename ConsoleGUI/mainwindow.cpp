#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_playRobotsButton_clicked(){

    if(currentPlayer != nullptr){ //make sure the current player exists

         Game *g = new Game(currentPlayer, dbTool); //create a new game

        RobotsGUI robotsGui(0); //play robots

        g->set_score(robotsGui.get_score()); //save the score to the game object
        pgh->add_game(g, currentPlayer); //add the game and player to the player game history

    }else{
    }
}

void MainWindow::on_playWormButton_clicked(){

    if(currentPlayer != nullptr){

        Game *g = new Game(currentPlayer, dbTool); //create a new game

        WormGUI wormGui (0); //play worm

        g->set_score(wormGui.get_score()); //save the score to the game object
        pgh->add_game(g, currentPlayer); //add the game and player to the player game history

    }else{
    }
}

void MainWindow::on_actionExit_Program_triggered(){
    close();
}

void MainWindow::on_actionNew_Player_triggered(){
    NewPlayerGui npg(0, pgh);
    currentPlayer = npg.get_current_player();
    npg.close();
}

void MainWindow::on_actionTop_3_Players_triggered(){
    TopThreePlayers ttp(0,pgh);
}

void MainWindow::on_actionSelect_Existing_Player_triggered(){
    ExistingPlayerGui epg(0, pgh);
    currentPlayer = epg.get_current_player();
    epg.close();
}

void MainWindow::on_actionCalculated_Statistics_triggered(){
    StatGui sg(0,pgh);
}

void MainWindow::on_actionTop_3_Games_triggered(){
    TopThreeGamesGui ttg(0,pgh);
}
