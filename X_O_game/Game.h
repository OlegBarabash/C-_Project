#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <iostream>
#include <cctype>
#include "Field.h"
#include "gamers.h"

class Game{
public:
    Game(){}
    void play_XO();
    ~Game();
protected:
    char what_game();
    void repeat();
    void play();
    void clear();
    void null_score();
    void result();
    bool x_or_y();

private:
    Field field;
    AbstractPlayer* players[2]={nullptr, nullptr};
    int score[2] = {0,0};
    int draw;
};

#endif // GAME_H_INCLUDED
