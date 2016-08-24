#ifndef GAMERS_H_INCLUDED
#define GAMERS_H_INCLUDED

#include <stdexcept>
#include <cctype>
#include <set>
#include <iostream>
#include "Field.h"

class AbstractPlayer
{
    char m_person;
    //std::set<char> possibleMove;
protected:
    //char *p_field;
    Field* m_field;
public:
    explicit AbstractPlayer(Field* f, char c='X'): m_person(toupper(c)), m_field(f)
    {
        if( m_person!='X' && m_person!='O' )
            throw std::logic_error("Wrong player.");
    }
    int getMoves()const { return m_field->turnsLeft(); }
    int makeMove(int i);
    //void set_possibleMove(std::set<char> i) { possibleMove = i; }
    //const void set_playerField( char *c) { p_field = c; }
    char person() const { return m_person; }
    virtual int do_turn() = 0;
    virtual ~AbstractPlayer(){}
};

class HumanPlayer: public AbstractPlayer
{
public:
    using AbstractPlayer::AbstractPlayer; //! Same as:
                                          //! HumanPlayer(char c='X'):  AbstractPlayer(c){}
    virtual int do_turn() override;
};

class RandomCompPlayer: public AbstractPlayer
{
public:
    using AbstractPlayer::AbstractPlayer;
    virtual int do_turn() override;
};

class SmartCompPlayer: public AbstractPlayer
{
public:
    using AbstractPlayer::AbstractPlayer;
    virtual int do_turn() override;
};

#endif // GAMERS_H_INCLUDED
