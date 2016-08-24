#include "Game.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void Game::clear()
{
    for(int i=0; i<2; ++i)
    {
        delete players[i];
        players[i] = nullptr;
    }
    field.clear();
}

void Game::null_score()
{
    score[0] = 0;
    score[1] = 0;
    draw = 0;
}

bool Game::x_or_y()
{
    bool xy;
    cout << "You want to be first?\n" <<
                "\tYes - \'1\'\n" <<
                "\tNo  - \'0\'" << endl;
    cin >> xy;
    return xy;
}

void Game::play_XO()
{
    bool keep_playing = true;
    while(keep_playing)
    {
        bool to_play = true;
        char wg = what_game();
        switch ( wg )
        {
        case '1':
        {
            if(x_or_y())
            {
                players[0] = new HumanPlayer(&field, 'X');
                players[1] = new RandomCompPlayer(&field,'O');
            }else{
                players[0] = new RandomCompPlayer(&field,'X');
                players[1] = new HumanPlayer(&field,'O');
            }
            break;
        }
        case '2':
        {
            if(x_or_y())
            {
                players[0] = new HumanPlayer(&field,'X');
                players[1] = new SmartCompPlayer(&field,'O');
            }else{
                players[0] = new SmartCompPlayer(&field,'X');
                players[1] = new HumanPlayer(&field,'O');
            }
            break;
        }
        case '3':
        {
            players[0] = new HumanPlayer(&field,'X');
            players[1] = new HumanPlayer(&field,'O');
            break;
        }
        case '4':
        {
            players[0] = new RandomCompPlayer(&field,'X');
            players[1] = new RandomCompPlayer(&field,'O');
            break;
        }
        case '5':
        {
            players[0] = new SmartCompPlayer(&field,'X');
            players[1] = new SmartCompPlayer(&field,'O');
            break;
        }
        case '6':
        {
            if(x_or_y())
            {
                players[0] = new SmartCompPlayer(&field,'X');
                players[1] = new RandomCompPlayer(&field,'O');
            }else{
                players[0] = new RandomCompPlayer(&field,'X');
                players[1] = new SmartCompPlayer(&field,'O');
            }
            break;
        }
        case '0':
        {
            keep_playing = false;
            break;
        }
        default:
            cout << "Only number from list" << endl;
            to_play = false;
        }

        while(to_play)
        {
            play();
            result();
            field.clear();
            cout << "Enter \'0\' - Go to menu.\n"
                 << "      \'1\' - Play again." << endl;
            int to;
            cin >> to;
            if(to == 1)
                to_play = true;
            else
            {
                to_play = false;
                null_score();
            }
        }
        clear();
    }
}

char Game::what_game()
{
    cout << "\t_____X_O_____" << endl;
    cout << "1.         Player vs Computer \n" <<
            "2.         Player vs Smart Computer \n" <<
            "3.         Player vs Player \n" <<
            "4.       Computer vs Computer \n" <<
            "5. Smart Computer vs Smart Computer \n"
            "6. Smart Computer vs Computer\n" <<
            "0. EXIT" << endl;
    char type_game;
    cin >> type_game;
    return type_game;
}

void Game::play()
{
    while(!field.check_if_win())
    {
        for(int i=0; i<2; ++i)
        {
            field.show_field();
            cout << endl;
            int ip = players[i]->do_turn();
            Field::Turn_results res = field.playerMove( ip, players[i]->person() );
            while(res == Field::T_BAD )
            {
                cout << "Try again. This cell is occupied or not exist" << endl;
                ip = players[i]->do_turn();
            }
            if( res == Field::T_DONE )
            {
                field.show_field();
                if(field.check_if_win())
                {
                    cout << "\tPlayer " << i+1 << " WIN!!!\n" << endl;
                    ++score[i];
                    return;
                }
                else
                {
                    cout << "\tDRAW!!! \nTry again!\n" << endl;
                    ++draw;
                    return;
                }
            }
        }
    }
}

void Game::result()
{
    cout <<   "Player 1: " << score[0]
         << "\nPlayer 2: " << score[1]
         << "\nDraw :    " << draw << endl;
}

Game::~Game()
 {
    clear();
 }
