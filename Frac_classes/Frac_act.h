#ifndef FRAC_ACT_H_INCLUDED
#define FRAC_ACT_H_INCLUDED
#include <iostream>
#include <cassert>

using namespace std;

class Drib
{

public:
    Drib(int c=0,int z=1):
    ch(c),zn(z)
    {
    reduce();
    }
    inline int get_zn()const
    {
        return zn;
    }
    inline int get_ch()const
    {
        return ch;
    }
    inline Drib& set_ch(int v)
    {
        ch = v;
        reduce();
        return *this;
    }
    inline Drib& set_zn(int v)
    {
        zn = v;
        reduce();
        return *this;
    }
    inline Drib& set_ch_zn(int c, int z)
    {
        ch = c;
        zn = z;
        reduce();
        return *this;
    }
    inline bool positive() const
    {
        assert (zn > 0);
        return ch >= 0;
    }
    inline Drib& negate()
    {
        assert (zn > 0);
        ch = -ch;
        return *this;
    }
    inline bool negative() const
    {
        return !positive();
    }

    Drib set_drib()
    {
        cin >> ch;
        cout << "/";
        cin >> zn;
        return *this;
    }

    void print ();
    Drib& operator *= (const int n);
    Drib& operator *= (const Drib &mn2);
    Drib& operator /= (const Drib &dilnuk);
    Drib& operator /= (const int n);
    Drib& operator += (const Drib &dod2);
    Drib& operator += (const int n);
    Drib& operator -= (const Drib &vid);
    Drib& operator -= (const int n);
    Drib operator- ()const;
    Drib& invert();

    inline bool operator == (const Drib &b)const
    {
        return ch == b.ch && zn == b.zn;
    }
    inline bool operator == (const int num)const
    {
        return ch == num && zn == 1;
    }
     inline bool operator!=(const Drib& num)const
    {
        return ch != num.ch || zn != num.zn;
    }
    inline bool operator!=(int num)const
    {
        return ch != num || zn != 1;
    }
    inline bool operator >(const Drib& num)const
    {
        return ch * num.zn > num.ch * zn;
    }
    inline bool operator >(int num)const
    {
        return ch > num * zn;
    }
    inline bool operator <(const Drib& num)const
    {
        return ch * num.zn < num.ch * zn;
    }
    inline bool operator <(int num)const
    {
        return ch < num * zn;
    }
    inline bool operator >=(const Drib& num)const
    {
        return ch * num.zn >= num.ch * zn;
    }
    inline bool operator>=(int num) const
    {
        return ch >= num * zn;
    }
    inline bool operator<=(const Drib& num) const
    {
        return ch * num.zn <= num.ch * zn;
    }
    inline bool operator<=(int num) const
    {
        return ch <= num * zn;
    }

    Drib pow (const Drib& base, int exponent);

private:
    int ch;
    int zn;
    void reduce();
};

inline ostream& operator<<(ostream& os, const Drib &d)
{
    os << d.get_ch() << '/' <<  d.get_zn();
    return os;
}

inline Drib operator+(Drib lhs, const Drib& rhs)
{
    return lhs += rhs;
}

inline Drib operator+(Drib lhs, int rhs)
{
    return lhs += rhs;
}

inline Drib operator+(int lhs, Drib rhs)
{
    return rhs += lhs;
}

inline Drib operator*(Drib lhs, const Drib& rhs)
{
    return lhs *= rhs;
}

inline Drib operator*(Drib lhs, int rhs)
{
    return lhs *= rhs;
}

inline Drib operator*(int lhs, Drib rhs)
{
    return rhs *= lhs;
}

inline Drib operator-(Drib lhs, const Drib& rhs)
{
    return lhs -= rhs;
}

inline Drib operator-(Drib lhs, int rhs)
{
    return lhs -= rhs;
}

inline Drib operator-(int lhs, Drib rhs)
{
    return (-rhs) += lhs;
}

inline Drib operator/(Drib lhs, const Drib& rhs)
{
    return lhs /= rhs;
}

inline Drib operator/(Drib lhs, int rhs)
{
    return lhs /= rhs;
}

inline Drib operator/(int lhs, Drib rhs)
{
    return rhs.invert() * lhs;
}

inline bool operator==(int lhs, const Drib& rhs)
{
    return rhs == lhs;
}

inline bool operator!=(int lhs, const Drib& rhs)
{
    return rhs != lhs;
}

inline bool operator>(int lhs, const Drib& rhs)
{
    return rhs < lhs;
}
inline bool operator>=(int lhs, const Drib& rhs)
{
    return rhs <= lhs;
}

inline bool operator<(int lhs, const Drib& rhs)
{
    return rhs > lhs;
}

inline bool operator<=(int lhs, const Drib& rhs)
{
    return rhs >= lhs;
}




#endif // FRAC_ACT_H_INCLUDED
