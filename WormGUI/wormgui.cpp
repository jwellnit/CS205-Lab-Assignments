#include "wormgui.h"
#include "ui_wormgui.h"

WormGUI::WormGUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WormGUI)
{
    ui->setupUi(this);
    ui->replay->hide();
    set_up(60, 32);
}

WormGUI::~WormGUI()
{
    delete ui;
}

void WormGUI::set_up(int rows, int cols){
    worm = new Worm(rows, cols);
    worm->draw(60, 32);
    continueGame = true;
    print();
    play_again();
}

void WormGUI::print(){

    // create an empty string
    QString temp_board = "";
    QString scoreBoard = "";

    // create a single string from the array that stores the gameboard
    for(int row = 0; row < worm->get_cols()-1; row++) {
        for(int col = 0; col < worm->get_rows()-1; col++) {
            temp_board += worm->examine_space(row, col);
        }
        temp_board += '\n';
    }

    // for debugging
    // std::cerr << temp_board.toStdString() << "\n";

    // clear the board
    ui->gameSpace->clear();

    // load the QString into the label
    ui->gameSpace->setText(temp_board);

    //update the scoreboard
    string a = to_string(worm->tailSize - 1);
    for (int i =0; i< a.length(); i++ ){
        scoreBoard += a[i];
    }

    ui->scoreBoard->clear(); //clear the score
    ui->scoreBoard->setText(scoreBoard); //load the QString into the label
}

void WormGUI::play_again(){
    ui->replay->hide();
    worm->draw(60,32);
    continueGame = true;
    print();
}

void WormGUI::on_w_button_clicked()
{
    worm->left_key();
    continueGame = worm->check_move();
    worm->check_hit();
    worm->update_board();

    worm->clear_shift();
    print();
    if(!continueGame){
        ui->replay->show();
    }
}

void WormGUI::on_s_button_clicked()
{
    worm->down_key();
    continueGame = worm->check_move();
    worm->check_hit();
    worm->update_board();

    worm->clear_shift();
    print();
    if(!continueGame){
        ui->replay->show();
    }
}

void WormGUI::on_quit_button_clicked()
{
  close();
}

void WormGUI::on_n_button_clicked()
{
    worm->up_key();
    continueGame = worm->check_move();
    worm->check_hit();
    worm->update_board();

    worm->clear_shift();
    print();
    if(!continueGame){
        ui->replay->show();
    }

}

void WormGUI::on_e_button_clicked()
{
    worm->right_key();
    continueGame = worm->check_move();
    worm->check_hit();
    worm->update_board();
    worm->clear_shift();
    print();
    if(!continueGame){
        ui->replay->show();
    }
}

void WormGUI::on_yes_clicked()
{
    play_again();
}

void WormGUI::on_no_clicked()
{
    close();
}

int WormGUI::get_score(){
    return worm->tailSize;
}
