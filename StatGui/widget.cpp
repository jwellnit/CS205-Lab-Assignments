#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent, PlayerGameHistory* pgh, Player* pl) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    p = pl;
    ph = pgh;

    calc_stats();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    this->close();
}

void Widget::calc_stats()
{

}
