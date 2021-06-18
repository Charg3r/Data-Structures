#include <iostream>
#include "Pile.h"

using namespace std;

int main()
{
    Pile p;
    p.push(5);
    p.push(10);
    p.push(15);

    cout << p.getTop()->getData() << endl;
    p.pop();
    cout << p.getTop()->getData() << endl;
}