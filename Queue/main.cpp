#include <iostream>
#include "Queue.h"

int main()
{
    Queue F1;

    F1.insert(10, "diez");
    F1.insert(8, "ocho");
    F1.insert(2, "dos");

    cout << F1.getFront()->getKey() << endl;
    cout << F1.getBack()->getKey() << endl;
    F1.del();

    cout << F1.getFront()->getKey() << endl;
    cout << F1.getBack()->getKey() << endl;
    F1.del();

    cout << F1.getFront()->getKey() << endl;
    cout << F1.getBack()->getKey() << endl;
    F1.del();

    cout << F1.getFront() << endl;

    return 0;
}