#include "selectexistingplayer.h"

//constructor
SelectExistingPlayer::SelectExistingPlayer(MainScreen *m){
    main = m;
    displayExistingPlayers();
}

//deconstructor
SelectExistingPlayer::~SelectExistingPlayer(){
}

//set up the key presses for selecting an existing player
void SelectExistingPlayer::displayExistingPlayers(){

    clear();

    set_up();

    continue_looping = true;

    //print the screen
    print();

    do {

        // draw the new screen
        refresh();

        // obtain character from keyboard
        int ch = getch();

        // operate based on input character
        switch (ch) {
        case '1':
            if(main->get_num_active_players() > 0){ //make sure that player exists

                //if it exists, make it the current player in main
                main->currentPlayer = main->get_player_game_history()->players[0];
                continue_looping    = false;

            }else{

                //if it does not exist, print out and return to mainscreen
                clear();

                mvprintw(0, 0, "Player does not exist");
                getch();

                continue_looping = false;

            }
            break;
        case '2':
            if(main->get_num_active_players() > 1){//make sure that player exists

                //if it exists, make it the current player in main
                main->currentPlayer = main->get_player_game_history()->players[1];
                continue_looping    = false;

            }else{

                //if it does not exist, print out and return to mainscreen
                clear();

                mvprintw(0, 0, "Player does not exist");
                getch();

                continue_looping = false;

            }
            break;
        case '3':
            if(main->get_player_game_history()->players[2]){ //make sure that player exists

                //if it exists, make it the current player in main
                main->currentPlayer = main->get_player_game_history()->players[2];
                continue_looping    = false;

            }else{

                //if it does not exist, print out and return to mainscreen
                clear();

                mvprintw(0, 0, "Player does not exist");
                getch();

                continue_looping = false;

            }
            break;
        case '4':
            if(main->get_player_game_history()->players[3]){ //make sure that player exists

                //if it exists, make it the current player in main
                main->currentPlayer = main->get_player_game_history()->players[3];
                continue_looping    = false;

            }else{

                //if it does not exist, print out and return to mainscreen
                clear();

                mvprintw(0, 0, "Player does not exist");
                getch();

                continue_looping = false;

            }
            break;
        case '5':
            if(main->get_player_game_history()->players[4]){ //make sure that player exists

                //if it exists, make it the current player in main
                main->currentPlayer = main->get_player_game_history()->players[4];
                continue_looping    = false;

            }else{

                //if it does not exist, print out and return to mainscreen
                clear();

                mvprintw(0, 0, "Player does not exist");
                getch();

                continue_looping = false;

            }
            break;
        case '6':
            if(main->get_player_game_history()->players[5]){ //make sure that player exists

                //if it exists, make it the current player in main
                main->currentPlayer = main->get_player_game_history()->players[5];
                continue_looping    = false;

            }else{

                //if it does not exist, print out and return to mainscreen
                clear();

                mvprintw(0, 0, "Player does not exist");
                getch();

                continue_looping = false;

            }
            break;
        case '7':
            if(main->get_player_game_history()->players[6]){ //make sure that player exists

                //if it exists, make it the current player in main
                main->currentPlayer = main->get_player_game_history()->players[6];
                continue_looping    = false;

            }else{

                //if it does not exist, print out and return to mainscreen
                clear();

                mvprintw(0, 0, "Player does not exist");
                getch();

                continue_looping = false;

            }
            break;
        case '8':
            if(main->get_player_game_history()->players[7]){ //make sure that player exists

                //if it exists, make it the current player in main
                main->currentPlayer = main->get_player_game_history()->players[7];
                continue_looping    = false;

            }else{

                //if it does not exist, print out and return to mainscreen
                clear();

                mvprintw(0, 0, "Player does not exist");
                getch();

                continue_looping = false;

            }
            break;
        case '9':
            if(main->get_player_game_history()->players[8]){ //make sure that player exists

                //if it exists, make it the current player in main
                main->currentPlayer = main->get_player_game_history()->players[8];
                continue_looping    = false;

            }else{

                //if it does not exist, print out and return to mainscreen
                clear();

                mvprintw(0, 0, "Player does not exist");
                getch();

                continue_looping = false;

            }
            break;
        }

        print();

    } while(continue_looping);

    refresh();

    //cleanup the window and return control to MainScreen
    endwin();

    return;
}

//print out the pgh
void SelectExistingPlayer::print(){

    PlayerGameHistory *ph = main->get_player_game_history();

    for(int i = 0; i < main->get_num_active_players(); i++){

        Player *p = ph->players[i];

        mvprintw(i, 0, to_string(i+1).c_str());
        mvprintw(i, 2, p->firstName.c_str());
    }
}
