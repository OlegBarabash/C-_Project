#ifndef FIELD_H_INCLUDED
#define FIELD_H_INCLUDED

//#include "gamers.h"
#include <set>
#include <cstdlib>

class Field{
public:
    enum Turn_results{T_CONT, T_DONE, T_BAD};
    Field() {}
    bool check_if_win();
    bool check_if_end();
    Turn_results playerMove(int ip, char c);
    void show_field();
    void clear();

    const std::set<char>& getPossibleTurns() const { return  m_possible_turns; }
    size_t turnsLeft() const { return  m_possible_turns.size(); }
    //const char* getField() const { return game_field; }
    char getCell(size_t idx) const { return game_field[idx]; }
    size_t getFieldSize() const { return 9; }

private:
    char game_field[9] = {'1','2','3','4','5','6','7','8','9'};
    std::set<char> m_possible_turns{std::begin(game_field), std::end(game_field)};
};


#endif // FIELD_H_INCLUDED
