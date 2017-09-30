#include "robots.h"

Robots::Robots(int rows, int cols) : Engine::Engine(rows, cols)
{
    //initializes all variables
    playerX = -1;
    playerY = -1;
    score = 0;
    isAlive = true;
    for (int i = 0; i < MAXENEMIES; i++) {
        enemyX[i] = -1;
        enemyY[i] = -1;
    }
    //SHOW_WHERE
}

Robots::Robots()
{
    //initializes all variables
    playerX = -1;
    playerY = -1;
    score = 0;
    isAlive = true;
    for (int i = 0; i < MAXENEMIES; i++) {
        enemyX[i] = -1;
        enemyY[i] = -1;
    }
    //SHOW_WHERE
}

// copy assignment
void Robots::operator = (Robots &obj) {
    rows = obj.rows;
    cols = obj.cols;

    // allocation
    gameBoard = obj.gameBoard;

    //initializes all variables
    playerX = obj.playerX;
    playerY = obj.playerY;
    score = obj.score;
    isAlive = obj.isAlive;
    for (int i = 0; i < MAXENEMIES; i ++) {
        enemyX[i] = obj.enemyX[i];
        enemyY[i] = obj.enemyY[i];
    }
    //SHOW_WHERE
}

Robots::~Robots()
{
    //SHOW_WHERE
}

//resets the game, other than score
void Robots::clear_board()
{
    //SHOW_WHERE
    //clears the board
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            set_space(i, j, ' ');
        }
    }

    //resets player and enemies
    playerX = -1;
    playerY = -1;
    score = 0;
    for (int i = 0; i < MAXENEMIES; i++) {
        enemyX[i] = -1;
        enemyY[i] = -1;
    }

    isAlive = true; // resets the end game variable
}

//places the enemies and the player on the board
void Robots::populate_board(int enemies)
{
    //SHOW_WHERE
    numEnemies = enemies;
    //puts the enemies in random spaces
    for(int i = 0; i < numEnemies; i++) {
        int x = -1;
        int y = -1;
        do {
            x = rand() % cols;
            y = rand() % rows;
        } while (examine_space(x, y) != ' '); // makes sure nothing's in the space
        enemyX[i] = x;
        enemyY[i] = y;
        set_space(x, y, 'r');
    }

    //places the player in an empty space
    int x = -1;
    int y = -1;
    do {
        x = rand() % cols;
        y = rand() % rows;
    } while (examine_space(x ,y) != ' ');
    playerX = x;
    playerY = y;
    set_space(x, y, 'h');
}

//randomizes enemy positions
void Robots::redraw_board()
{
    //SHOW_WHERE
    for(int i = 0; i < MAXENEMIES; i++) {
        if (enemyX[i] != -1) {
            int x = -1;
            int y = -1;
            do {
                x = rand() % cols;
                y = rand() % rows;
            } while (examine_space(x, y) != ' '); // makes sure space is empty
            set_space(enemyX[i], enemyY[i], ' ');
            enemyX[i] = x;
            enemyY[i] = y;
            set_space(x, y, 'r');
        }
    }
}

//checks if a move is allowed
//the player cannot move if it will cause their death
bool Robots::can_move(int x, int y)
{
    //SHOW_WHERE
    //if the space doesnt exist
    if (x < 0 || y < 0 || x >= cols || y >= rows) {
        return false;
    }

    //if the space is occupied
    if (examine_space(x, y) != ' ') {
        return false;    void debug_print();
    }

    //variables for surrounding spaces
    int lessX = x - 1;
    int lessY = y - 1;
    int moreX = x + 1;
    int moreY = y + 1;


    //next eight check to see if surrounding spaces are occupied
    if (lessX >= 0) {
        if (examine_space(lessX, y) != ' ' &&
                examine_space(lessX, y) != 'h') {
            return false;
        }
    }

    if (lessY >= 0) {
        if (examine_space(x, lessY) != ' ' &&
                examine_space(x, lessY) != 'h') {
            return false;
        }
    }

    if (moreX <= cols - 1) {
        if (examine_space(moreX, y) != ' ' &&
                examine_space(moreX, y) != 'h') {
            return false;
        }
    }

    if (moreY <= rows - 1) {
        if (examine_space(x, moreY) != ' ' &&
                examine_space(x, moreY) != 'h' ) {
            return false;
        }
    }

    if (lessX >= 0 && moreY <= rows - 1) {
        if (examine_space(lessX, moreY) != ' '
                && examine_space(lessX, moreY) != 'h') {
            return false;
        }
    }

    if (lessY >= 0 && moreX <= cols - 1) {
        if (examine_space(moreX, lessY) != ' '
                && examine_space(moreX, lessY) != 'h') {
            return false;
        }
    }

    if (moreX <= cols - 1 && moreY <= rows - 1) {
        if (examine_space(moreX, moreY) != ' '
                && examine_space(moreX, moreY) != 'h') {
            return false;
        }
    }

    if (lessX >= 0 && lessY >= 0) {
        if (examine_space(lessX, lessY) != ' '
                && examine_space(lessX, lessY) != 'h') {
            return false;
        }
    }

    //all conditions failed, move safe
    return true;
}

//evaluates player input and acts accordingly
bool Robots::move(char in)
{
    //SHOW_WHERE

    bool enemyAlive = false;

    for (int i = 0; i < MAXENEMIES; i++) {
        if (enemyX[i] != -1) {
            enemyAlive = true;
        }
    }

    if (!enemyAlive) {
        if (numEnemies < MAXENEMIES) {
            numEnemies += 5;
            clear_board();
            populate_board(numEnemies);
        }
    }

    int x = playerX;
    int y = playerY;
    switch (in) {
    case 'k':
        //moves the player up if possible
        x = playerX;
        y = playerY - 1;
        if (can_move(x, y)) {
            set_space(playerX, playerY, ' ');
            set_space(x, y, 'h');
            playerX = x;
            playerY = y;

            //move robots in response
            for (int i = 0; i < MAXENEMIES; i++) {
                if (enemyX[i] != -1) {
                    pursue(i);
                }
            }

            return true;
        } else {
            return false;
        }
        break;

    case 'h':
        //moves the player left if possible
        x = playerX - 1;
        y = playerY;
        if (can_move(x, y)) {
            set_space(playerX, playerY, ' ');
            set_space(x, y, 'h');
            playerX = x;
            playerY = y;

            //move robots in response
            for (int i = 0; i < MAXENEMIES; i++) {
                if (enemyX[i] != -1) {
                    pursue(i);
                }
            }

            return true;
        } else {
            return false;
        }
        break;

    case 'l':
        //moves the player right if possible
        x = playerX + 1;
        y = playerY;
        if (can_move(x, y)) {
            set_space(playerX, playerY, ' ');
            set_space(x, y, 'h');
            playerX = x;
            playerY = y;

            //move robots in response
            for (int i = 0; i < MAXENEMIES; i++) {
                if (enemyX[i] != -1) {
                    pursue(i);
                }
            }

            return true;
        } else {
            return false;
        }
        break;

    case 'j':
        //moves the player down if possible
        x = playerX;
        y = playerY + 1;
        if (can_move(x, y)) {
            set_space(playerX, playerY, ' ');
            set_space(x, y, 'h');
            playerX = x;
            playerY = y;

            //move robots in response
            for (int i = 0; i < MAXENEMIES; i++) {
                if (enemyX[i] != -1) {
                    pursue(i);
                }
            }

            return true;
        } else {
            return false;
        }
        break;

    case 'y':
        //moves the player up and left if possible
        x = playerX - 1;
        y = playerY - 1;
        if (can_move(x, y)) {
            set_space(playerX, playerY, ' ');
            set_space(x, y, 'h');
            playerX = x;
            playerY = y;

            //move robots in response
            for (int i = 0; i < MAXENEMIES; i++) {
                if (enemyX[i] != -1) {
                    pursue(i);
                }
            }

            return true;
        } else {
            return false;
        }
        break;

    case 'u':
        //moves the player up and right if possible
        x = playerX + 1;
        y = playerY - 1;
        if (can_move(x, y)) {
            set_space(playerX, playerY, ' ');
            set_space(x, y, 'h');
            playerX = x;
            playerY = y;

            //move robots in response
            for (int i = 0; i < MAXENEMIES; i++) {
                if (enemyX[i] != -1) {
                    pursue(i);
                }
            }

            return true;
        } else {
            return false;
        }
        break;

    case 'b':
        //moves the player down and left if possible
        x = playerX - 1;
        y = playerY + 1;
        if (can_move(x, y)) {
            set_space(playerX, playerY, ' ');
            set_space(x, y, 'h');
            playerX = x;
            playerY = y;

            //move robots in response
            for (int i = 0; i < MAXENEMIES; i++) {
                if (enemyX[i] != -1) {
                    pursue(i);
                }
            }

            return true;
        } else {
            return false;
        }
        break;

    case 'n':
        //moves the player down and right if possible
        x = playerX + 1;
        y = playerY + 1;
        if (can_move(x, y)) {
            set_space(playerX, playerY, ' ');
            set_space(x, y, 'h');
            playerX = x;
            playerY = y;

            //move robots in response
            for (int i = 0; i < MAXENEMIES; i++) {
                if (enemyX[i] != -1) {
                    pursue(i);
                }
            }

            return true;
        } else {
            return false;
        }
        break;

    case 't':
        //teleports the player
        teleport();

        //move robots in response
        for (int i = 0; i < MAXENEMIES; i++) {
            if (enemyX[i] != -1) {
                pursue(i);
            }
        }

        return true;
        break;

    case 'q':
        //quits the game
        quit();
        return true;
        break;

    case '>':
        //continues until just before the player dies
        go_safe();
        return true;
        break;

    case 'w':
        //continues until either the robots or player die
        go();
        return true;
        break;

    case (char)0x0c:
        //redraws the board
        redraw_board();
        return true;
        break;

    case '.':
    case ' ':
        //move robots in response
        for (int i = 0; i < MAXENEMIES; i++) {
            if (enemyX[i] != -1) {
                pursue(i);
            }
        }

    default:
        return true;
    }
}

//randomizes the player's position
void Robots::teleport()
{
    //SHOW_WHERE
    set_space(playerX, playerY, ' ');
    playerX = rand() % cols;
    playerY = rand() % rows;

    //if player lands on a robot or trash, die
    if (examine_space(playerX, playerY) != ' ') {
        game_over();
    } else {
        set_space(playerX, playerY, 'h');
    }
}

//robots follow the player
void Robots::pursue(int i)
{
    //SHOW_WHERE
    //disables a robot if it was destroyed in the previous turn
    if (examine_space(enemyX[i], enemyY[i]) == '*') {
        enemyX[i] = -1;
        enemyY[i] = -1;
        return;
    }

    int x = -1;
    int y = -1;

    //moves in the x direction towards the player
    if (enemyX[i] < playerX) {
        x = enemyX[i] + 1;
    } else if (enemyX[i] > playerX) {
        x = enemyX[i] - 1;
    }  else {
        x = enemyX[i];
    }

    //moves in the y direction towards the player
    if (enemyY[i] < playerY) {
        y = enemyY[i] + 1;
    } else if (enemyY[i] > playerY) {
        y = enemyY[i] - 1;
    } else {
        y = enemyY[i];
    }

    //moves into a space if empty
    if (examine_space(x, y) == ' ') {
        set_space(enemyX[i], enemyY[i], ' ');
        enemyX[i] = x;
        enemyY[i] = y;
        set_space(x, y, 'r');
        //collides with another robot
    } else if (examine_space(x, y) == 'r') {
        set_space(enemyX[i], enemyY[i], ' ');
        enemyX[i] = -1;
        enemyY[i] = -1;
        set_space(x, y, '*');
        score += 20;
        //collides with a trash pile
    }  else if (examine_space(x, y) == '*') {
        set_space(enemyX[i], enemyY[i], ' ');
        enemyX[i] = -1;
        enemyY[i] = -1;
        score += 10;
        //collides with the player
    }  else if (examine_space(x, y) == 'h') {
        game_over();
    }
}

//goes until player or robots die
void Robots::go()
{
    //SHOW_WHERE
    //break recursion if game over
    if (!isAlive) {
        return;
    }

    bool enemyAlive = false;

    for (int i = 0; i < MAXENEMIES; i++) {
        if (enemyX[i] != -1) {
            enemyAlive = true;
        }
    }

    if (!enemyAlive) {
        return;
    }

    //all enemies purse
    for (int i = 0; i < MAXENEMIES; i++) {
        if (enemyX[i] != -1) {
            pursue(i);
        }
    }
    go(); // recursive call
    return;
}

void Robots::go_safe()
{
    //SHOW_WHERE
    //break recursion if game over
    if (!isAlive) {
        return;
    }

    bool enemyAlive = false;

    for (int i = 0; i < MAXENEMIES; i++) {
        if (enemyX[i] != -1) {
            enemyAlive = true;
        }
    }

    if (!enemyAlive) {
        return;
    }

    //location variables
    int x = playerX;
    int y = playerY;
    int lessX = playerX - 1;
    int lessY = playerY - 1;
    int moreX = playerX + 1;
    int moreY = playerY + 1;

    //next 8 check if a robot is next to the player
    //break recursion if yes
    if (lessX >= 0) {
        if (examine_space(lessX, y) == 'r') {
            return;
        }
    }

    if (lessY >= 0) {
        if (examine_space(x, lessY) == 'r') {
            return;
        }
    }

    if (moreX <= cols) {
        if (examine_space(moreX, y) == 'r') {
            return;
        }
    }

    if (moreY <= rows) {
        if (examine_space(x, moreY) == 'r') {
            return;
        }
    }

    if (lessX >= 0 && moreY <= rows) {
        if (examine_space(lessX, moreY) == 'r') {
            return;
        }
    }

    if (lessY >= 0 && moreX <= cols) {
        if (examine_space(moreX, lessY)  == 'r') {
            return;
        }
    }

    if (moreX <= cols && moreY <= rows) {
        if (examine_space(moreX, moreY) == 'r') {
            return;
        }
    }

    if (lessX >= 0 && lessY >= 0) {
        if (examine_space(lessX, lessY) == 'r') {
            return;
        }
    }

    //all enemies purse
    for (int i = 0; i < MAXENEMIES; i++) {
        if (enemyX[i] != -1) {
            pursue(i);
        }
    }
    go_safe();//recursive call
    return;
}

//kills the player
void Robots::game_over()
{
    //SHOW_WHERE
    isAlive = false;
}

//quits the game
void Robots::quit()
{
    //SHOW_WHERE
    //exit(0);
    game_over();
}

//manually create an enemy
void Robots::create_enemy(int x, int y)
{
    //SHOW_WHERE
    int i = 0;
    while (enemyX[i] != -1) {
        i++;
    }
    enemyX[i] = x;
    enemyY[i] = y;
    set_space(x, y, 'r');
}

//manually place the player
void Robots::create_player(int x, int y)
{
    //SHOW_WHERE
    playerX = x;
    playerY = y;
    set_space(x ,y ,'h');
}

//return the player's life status
bool Robots::get_status() {
    //SHOW_WHERE
    return isAlive;
}

