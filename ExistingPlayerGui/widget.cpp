#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent, PlayerGameHistory *pgh) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    for(int i = 0; i < pgh.num_activce_players(); i++){
        ui->playerList->addItem(pgh.players.at(i).firstName);
    }
}

Widget::~Widget(){
    delete ui;
}




void Widget::on_okayButton_clicked(){
   currentPlayer = ui->playerList->currentItem();
}

void Widget::close_this(){
    this->close();
}

Player* Widget::get_current_player(){
    return currentPlayer;
}
