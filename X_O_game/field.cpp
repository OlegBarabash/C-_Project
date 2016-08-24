#include "Field.h"
#include "gamers.h"
#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;

void Field::show_field()
{
    cout << "\t " << game_field[0] << " | " << game_field[1] << " | " << game_field[2]<< " \n"
         << "\t-----------\n"
         << "\t " << game_field[3] << " | " << game_field[4] << " | " << game_field[5]<< " \n"
         << "\t-----------\n"
         << "\t " << game_field[6] << " | " << game_field[7] << " | " << game_field[8]<< " " << endl;
}

bool Field::check_if_win()
{
    for(int i = 0; i <= 8; i+=3)
    {
        if(game_field[i] == game_field[i+1] && game_field[i+1] == game_field[i+2] && ( game_field[i] == 'X' || game_field[i] == 'O') )
            return true;
    }
    for(int i = 0; i <= 2; ++i)
    {
        if(game_field[i] == game_field[i+3] && game_field[i+3] == game_field[i+6] && ( game_field[i] == 'X' || game_field[i] == 'O') )
            return true;
    }
    for(int i = 0; i <= 2; i+=2)
    {
        if(game_field[i] == game_field[4] && game_field[4] == game_field[8-i] && ( game_field[i] == 'X' || game_field[i] == 'O') )
            return true;
    }
    return false;
}

bool Field::check_if_end()
{
    return m_possible_turns.empty() || check_if_win();
}

Field::Turn_results Field::playerMove(int ip, char c)
{
    //player->set_possibleMove(m_possible_turns);
    //player->set_playerField(game_field);
//    int ip = player->do_turn();

    if ( !( ip>=0 && ip<=8 && toupper(game_field[ip]) != 'X' && toupper(game_field[ip]) != 'O') )
    {
        return T_BAD;
        //cout << "Try again. This cell is occupied or not exist" << endl;
        //ip = player->do_turn();
    }
    m_possible_turns.erase(m_possible_turns.find(game_field[ip]));
    //game_field[ip] = player->person();
    game_field[ip] = c;

    return check_if_end() ? T_DONE : T_CONT;
}

void Field::clear()
{
    char c = '1';
    for(int i = 0; i <= 8; ++i )
    {
        game_field[i] = c;
        ++c;
    }
    m_possible_turns.clear();
    m_possible_turns = {std::begin(game_field), std::end(game_field)};
}
