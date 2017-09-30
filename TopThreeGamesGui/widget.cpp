#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent, PlayerGameHistory* pgh, Player* pl) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ph = pgh;
    g  = ph->games;

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
    // loop through to find the top players
    if (g.size() >= 3) {

        g1 = g[0];

        int g1i = 0;

        for (int i = 0; i < g.size(); i++) {
            if (ph->get_score(g[i]) >= ph->get_score(g1)) {

                g1  = g[i];
                g1i = i;
            }
        }

        g[g1i] = nullptr;

        g.shrink_to_fit();

        g2 = g[0];

        int g2i = 0;

        for (int i = 0; i < g.size(); i++) {
            if (ph->get_score(g[i]) >= ph->get_score(g2)) {

                g2  = g[i];
                g2i = i;
            }
        }

        g[g2i] = nullptr;

        g.shrink_to_fit();

        g3 = g[0];

        int g3i = 0;

        for (int i = 0; i < g.size(); i++) {
            if (ph->get_score(g[i]) >= ph->get_score(g3)) {

                g3  = g[i];
                g3i = i;
            }
        }

        g[g3i] = nullptr;

        g.shrink_to_fit();

        g = ph->games;

        // get text for labels
        string f  = g1->name + ", " + to_string(g1->score);
        string s = g2->name + ", " + to_string(g2->score);
        string t  = g3->name + ", " + to_string(g3->score);

        QString first  = QString::fromStdString(f);
        QString second = QString::fromStdString(s);
        QString third  = QString::fromStdString(t);

        // clear the labels
        ui->firstResult->clear();
        ui->secondResult->clear();
        ui->thirdResult->clear();

        // load the QString into the label
        ui->firstResult->setText(first);
        ui->secondResult->setText(second);
        ui->thirdResult->setText(third);
    } else {
        // get text for labels
        QString first  = "N/A";
        QString second = "N/A";
        QString third  = "N/A";

        // clear the labels
        ui->firstResult->clear();
        ui->secondResult->clear();
        ui->thirdResult->clear();

        // load the QString into the label
        ui->firstResult->setText(first);
        ui->secondResult->setText(second);
        ui->thirdResult->setText(third);
    }
}
