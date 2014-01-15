#pragma once
#include <string>
using namespace std;
#include "event.h"


class evt_str : evt_field
{
    public:
        evt_str(string s)
        {
            this->type = et_string;
            this->data = new string;
            *(string*)this->data = s;
        }
};
