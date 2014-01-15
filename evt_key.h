#pragma once
#include "event.h"

class evt_key : evt_field
{
    public:
    evt_key(char c)
    {
        this->type = et_number;
        this->data = new double;
        *(double*)this->data = c;
    }
};
