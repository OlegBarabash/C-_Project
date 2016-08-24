#include "gamers.h"
#include "Field.h"
#include <iostream>
#include <cstdlib>
#include <set>
#include <cctype>

using std::cout;
using std::cin;
using std::endl;

int AbstractPlayer::makeMove(int i)
{
    const auto& pM = m_field->getPossibleTurns();
    for(auto j : pM)
    {
        if(i == 1)
        {
            int res = j - 49;
            return res;
        }else{
            --i;
        }
    }
    throw std::logic_error("Wrong comp move.");
    return i;
}

int HumanPlayer::do_turn()
{
    cout << "Player " << person() << " - ";
    int cp;
    cin >> cp;
    return cp - 1;
}

int RandomCompPlayer::do_turn()
{
    int ip = rand() % getMoves() + 1;
    ip = makeMove(ip);
    cout << "Comp " << person() << " - " << ip+1 << endl;
    return ip;
}

int SmartCompPlayer::do_turn()
{
    for(int i = 0; i <= 2; i+=2)
    {
        if( (person() == m_field->getCell(i) || isdigit(m_field->getCell(i)) )
            && (person() == m_field->getCell(4) || isdigit(m_field->getCell(i)))
            && ((person() == m_field->getCell(8-i)) || isdigit(m_field->getCell(8-i))) )
        {
            if( isdigit(m_field->getCell(4)))
            {
                cout << "SmartComp " << person() << " - " << 5 << endl;
                return 4;
            }
            for(int j = i; j <= 8-i; j+=(4-i))
            {
                if( person() != m_field->getCell(j) )
                {
                    cout << "SmartComp " << person() << " - " << j+1 << endl;
                    return j;
                }
            }
        }
    }
    for(int i = 0; i <= 8; i+=3)
    {
        if( (person() == m_field->getCell(i) || isdigit(m_field->getCell(i)) )
            && (person() == m_field->getCell(i+1) || isdigit(m_field->getCell(i+1)))
            && (person() == m_field->getCell(i+2) || isdigit(m_field->getCell(i+2))) )
        {
            for(int j = i; j <= i+2; ++j)
            {
                if( person() != m_field->getCell(j) )
                {
                    cout << "SmartComp " << person() << " - " << j+1 << endl;
                    return j;
                }
            }
        }
    }
    for(int i = 0; i <= 2; ++i)
    {
        if( (person() == m_field->getCell(i) || isdigit(m_field->getCell(i)) )
            && (person() == m_field->getCell(i+3) || isdigit(m_field->getCell(i+3)))
            && (person() == m_field->getCell(i+6) || isdigit(m_field->getCell(i+6))) )
        {
            for(int j = i; j <= i+6; j+=3)
            {
                if( person() != m_field->getCell(j) )
                {
                    cout << "SmartComp " << person() << " - " << j+1 << endl;
                    return j;
                }
            }
        }
    }
    int ip = rand() % getMoves() + 1;
    ip = makeMove(ip);
    cout << "SmartComp " << person() << " - " << ip+1 << endl;
    return ip;
}
