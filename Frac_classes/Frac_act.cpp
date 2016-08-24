#include "Frac_act.h"
#include <iostream>

using namespace std;


void Drib::reduce()
{
    Drib temp = *this;
    if (ch < 0)
        temp.ch = -temp.ch;
    else if (zn < 0)
        temp.zn = -temp.zn;

    while (temp.ch != 0 && temp.zn != 0)
    {
        if (temp.ch > temp.zn)
            temp.ch %= temp.zn;
        else
            temp.zn %= temp.ch;
    }
    ch /= (temp.ch + temp.zn);
    zn /= (temp.ch + temp.zn);

    if (ch == 0)
        zn = 1;
    if (zn < 0)
    {
        ch = -ch;
        zn = -zn;
    }
}

Drib& Drib::operator *= (const int n)
{
    ch *= n;
    reduce();
    return *this;
}

Drib& Drib::operator *= (const Drib &mn2)
{
    ch *= mn2.ch;
    zn *= mn2.zn;
    reduce();
    return *this;
}

Drib& Drib::operator /= (const Drib &dilnuk)
{
    ch *= dilnuk.zn;
    zn *= dilnuk.ch;
    reduce();
    return *this;
}

Drib& Drib::operator /= (const int n)
{
    zn *= n;
    reduce();
    return *this;
}

Drib& Drib::operator += (const Drib &dod2)
{
    ch = dod2.zn * ch + dod2.ch * zn;
    zn *= dod2.zn;
    reduce();
    return *this;
}

Drib& Drib::operator += (const int n)
{
    ch = ch + zn * n;
    reduce();
    return *this;
}

Drib& Drib::operator -= (const Drib &vid)
{
    ch = vid.zn * ch - vid.ch * zn;
    zn *= vid.zn;
    reduce();
    return *this;
}

Drib& Drib::operator -= (const int n)
{
    ch = ch - zn * n;
    reduce();
    return *this;
}


Drib Drib::operator- ()const
{
    Drib res(*this);
    res.ch = -res.ch;
    return res;
}

Drib& Drib::invert()
{
    int temp = ch;
    ch = zn;
    zn = temp;
    return *this;
}

Drib Drib::pow (const Drib& base, int exponent)
{
    if(exponent<0)
        return 1/pow(base, -exponent);
    if(exponent == 0)
        return Drib(1);
    Drib res = pow(base, exponent/2);
    if( exponent % 2 == 0)
    {
        return res*res;
    }else
    {
        return res*res*base;
    }
}

