#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent, PlayerGameHistory* pgh):
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->pgh = pgh;
    this->p = p;
}

Widget::~Widget(){
    delete ui;
}

void Widget::on_okayButton_clicked(){

    //save player info
    firstName = ui->firstNameLine->text();
    lastName  = ui->lastNameLine->text();
    address   = ui->addressLine->text();

    //create and set up a new player object with the inputted info
    Player* player = new Player(pgh->database);
    player->set_information(firstName.toStdString(), lastName.toStdString(), address.toStdString());
    currentPlayer = player;
}

Player* Widget::get_current_player(){
    return currentPlayer;
}

void Widget::close_this(){
    this->close();
}
