#include "Dyn_Drib.h"
#include <iostream>

using namespace std;

void Dyn_Drib::resize(size_t new_size, int def)
{
    if( new_size == q_size )
        return;

    size_t copy_data_size = new_size > q_size ? q_size : new_size;
    capacity = 2*(copy_data_size+1);
    Drib *new_data = new Drib[capacity];
    for(size_t i=0; i<copy_data_size; ++i )
    {
        new_data[i] = data[i];
    }
    for(size_t i=copy_data_size; i<capacity; ++i )
    {
        new_data[i] = def;
    }
    delete[] data;
    data = new_data;
    q_size = new_size;
}

Dyn_Drib& Dyn_Drib::set_frac()
{
    for (; q_size<capacity; ++q_size)
    {
        data[q_size].set_drib();

        if (data[q_size].get_ch() == 0 || data[q_size].get_zn() == 0)
        {
            break;
        }
        else if (q_size == capacity-1)
        {
            capacity = 2*(q_size+1);
            Drib *new_data = new Drib[capacity];
            for (size_t i=0; i<=q_size; ++i)
            {
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;
        }
    }
    return *this;
}

Dyn_Drib& Dyn_Drib::operator=(const Dyn_Drib &original)
{
    if (this != &original)
    {
        delete[] data;
        q_size = original.q_size;
        capacity = original.capacity;
        data = new Drib[capacity];
        for (unsigned int i=0; i<=q_size; ++i)
        {
            data[i] = original.data[i];
        }
    }

    return *this;
}

void Dyn_Drib::clear()
{
    delete[] data;
    data = 0;
    q_size = 0;
    capacity = (2*(q_size+1));
}
