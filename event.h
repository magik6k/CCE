#pragma once

using namespace std;

enum evt_type
{
    et_boolean,
    et_string,
    et_integer,
    et_number
};

class evt_field
{
    public:
        evt_type type;
        void* data;
};

class event
{
    private:

    public:
        evt_field* data;
        unsigned short len;

        event(evt_field* d, unsigned short l);
        event(const event& i);
        event(int argc, ...);
        event();
        ~event();
        event& operator=(const event& i);


};
