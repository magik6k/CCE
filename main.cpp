#include <iostream>
#include "vm.h"
#include "key.h"
#include "thread.h"
#include "term.h"
using namespace std;

int main()
{
    cout << "[CCE] Init" << endl;
    //term::init();
    thread* thKbd = new thread(keyGrabber::run);
    vm* machine = new vm;



    return 0;
}
