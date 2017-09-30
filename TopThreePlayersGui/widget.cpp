#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent, PlayerGameHistory* pgh, Player* pl) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ph = pgh;
    p = ph->players;

    calc_winners();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    this->close();
}

void Widget::calc_winners()
{

}

