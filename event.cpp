#include "event.h"
#include <stdarg.h>

event::event()
{
    this->data = nullptr;
    this->len = 0;
}

event::event(evt_field* d, unsigned short l)
{
    this->data = new evt_field[l];
    this->len = l;
    for(unsigned int n = 0; n < l; ++n)
    {
        this->data[n] = d[n];
    }
}

event::event(const event& i)
{
    this->data = new evt_field[i.len];
    this->len = i.len;
    for(unsigned int n = 0; n < i.len; ++n)
    {
        this->data[n] = i.data[n];
    }
}

event::event(int i, ...)
{
    this->data = new evt_field[i];
    this->len = i;
    va_list vl;
    va_start(vl,i);
    for(int n = 0; n < i; ++n)
    {
        this->data[n] = va_arg(vl,evt_field);
    }
    va_end(vl);
}

event::~event()
{
    delete[] this->data;
}

event& event::operator=(const event& i)
{
    if(this->data)
    {
        delete[] this->data;
    }
    this->data = new evt_field[i.len];
    this->len = i.len;
    for(unsigned int n = 0; n < i.len; ++n)
    {
        this->data[n] = i.data[n];
    }
    return *this;

}
