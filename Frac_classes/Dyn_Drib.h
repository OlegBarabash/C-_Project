#ifndef DYN_DRIB_H_INCLUDED
#define DYN_DRIB_H_INCLUDED

#include <iostream>
#include <cassert>
#include "Frac_act.h"


class Dyn_Drib
{
public:
    Dyn_Drib(size_t is=0):
        q_size(is),capacity(2*(is+1))
    {
        data = new Drib[capacity];
    }
    ~Dyn_Drib()
    {
        delete[] data;
    }

    void push_back(const Drib& d)
    {
        resize(q_size+1);
        data[q_size-1] = d;
    }
    void resize(size_t new_size, int def=0);
    Dyn_Drib& set_frac();
    Dyn_Drib& operator=(const Dyn_Drib &original);

    inline size_t size() const
    {
        return q_size;
    }

       inline bool is_empty() const
    {
        return q_size==0;
    }

    void clear();
    inline const Drib& operator[](size_t q_si)const
    {
        return data[q_si];
    }
    inline Drib& operator[](size_t q_si)
    {
        return data[q_si];
    }

    inline void show_frac()const
    {
        for(unsigned int i=0; i<q_size; ++i)
        {
            cout << data[i].get_ch() << "/" << data[i].get_zn() << ", " ;
        }
    }

private:
    size_t q_size;
    size_t capacity;
    Drib *data;
};




#endif // DYN_DRIB_H_INCLUDED
