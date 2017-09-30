#include "robotsgui.h"
#include "ui_robotsgui.h"

RobotsGUI::RobotsGUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RobotsGUI)
{
    ui->setupUi(this);
    ui->splitter->hide();
    set_up(15, 45, 5);
}

RobotsGUI::~RobotsGUI()
{
    delete ui;
}

void RobotsGUI::on_up_clicked()
{
    if (!r->get_status()) {
        return;
    }

    r->move('k');

    if (!r->get_status()) {
        ui->splitter->show();
    }

    print();
}

void RobotsGUI::on_right_clicked()
{
    if (!r->get_status()) {
        return;
    }

    r->move('l');

    if (!r->get_status()) {
        ui->splitter->show();
    }

    print();
}

void RobotsGUI::on_left_clicked()
{
    if (!r->get_status()) {
        return;
    }

    r->move('h');

    if (!r->get_status()) {
        ui->splitter->show();
    }

    print();
}

void RobotsGUI::on_down_clicked()
{
    if (!r->get_status()) {
        return;
    }

    r->move('j');

    if (!r->get_status()) {
        ui->splitter->show();
    }

    print();
}

void RobotsGUI::on_upLeft_clicked()
{
    if (!r->get_status()) {
        return;
    }

    r->move('y');

    if (!r->get_status()) {
        ui->splitter->show();
    }

    print();
}

void RobotsGUI::on_upRight_clicked()
{
    if (!r->get_status()) {
        return;
    }

    r->move('u');

    if (!r->get_status()) {
        ui->splitter->show();
    }

    print();
}

void RobotsGUI::on_downLeft_clicked()
{
    if (!r->get_status()) {
        return;
    }

    r->move('b');

    if (!r->get_status()) {
        ui->splitter->show();
    }

    print();
}

void RobotsGUI::on_downRight_clicked()
{
    if (!r->get_status()) {
        return;
    }

    r->move('n');

    if (!r->get_status()) {
        ui->splitter->show();
    }

    print();
}

void RobotsGUI::on_wait_clicked()
{
    if (!r->get_status()) {
        return;
    }

    r->move('w');

    if (!r->get_status()) {
        ui->splitter->show();
    }

    print();
}

void RobotsGUI::on_waitSafe_clicked()
{
    if (!r->get_status()) {
        return;
    }

    r->move('>');

    if (!r->get_status()) {
        ui->splitter->show();
    }

    print();
}

void RobotsGUI::on_skip_clicked()
{
    if (!r->get_status()) {
        return;
    }

    r->move('.');

    if (!r->get_status()) {
        ui->splitter->show();
    }

    print();
}

void RobotsGUI::on_teleport_clicked()
{
    if (!r->get_status()) {
        return;
    }

    r->move('t');

    if (!r->get_status()) {
        ui->splitter->show();
    }

    print();
}

void RobotsGUI::on_redraw_clicked()
{
    if (!r->get_status()) {
        return;
    }

    r->move((char)0x0c);

    if (!r->get_status()) {
        ui->splitter->show();
    }

    print();
}

void RobotsGUI::on_quit_clicked()
{
    if (!r->get_status()) {
        return;
    }

    r->move('q');

    if (!r->get_status()) {
        ui->splitter->show();
    }

    print();
}

void RobotsGUI::on_yes_clicked()
{
    play_again();
}

void RobotsGUI::on_no_clicked()
{
    this->close();
}

void RobotsGUI::print()
{
    // create an empty string
      QString temp_board = "";
      int rows = r->get_rows();
      int cols = r->get_cols();

      // create a single string from the array that stores the gameboard
      for(int row = 0; row < rows; row++) {
          for(int col = 0; col < cols; col++) {
              temp_board += r->examine_space(col, row);
          }
          temp_board += '\n';
      }

      // for debugging
      // std::cerr << temp_board.toStdString() << "\n";

      // clear the board
      ui->gameSpace->clear();

      // load the QString into the label
      ui->gameSpace->setText(temp_board);

}

void RobotsGUI::set_up(int rows, int cols, int startEnemies)
{
    r = new Robots(rows, cols);
    numEnemies = startEnemies;
    play_again();
}

void RobotsGUI::play_again()
{
    ui->splitter->hide();
    r->clear_board();
    r->populate_board(numEnemies);
    print();
}

int RobotsGUI::get_score(){
    return r->score;
}
