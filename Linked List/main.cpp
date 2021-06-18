#include <iostream>
#include "Node.h"
#include "LinkedList.h"

using namespace std;

int main()
{
	LinkedList l1, l2, l3;
	l1.insertOrder(5);
	l1.insertOrder(4);
	l1.insertOrder(25);
	l1.insertOrder(10);
	l1.insertOrder(0);

	l2.insertStart(12);
	l2.insertStart(13);
	l2.insertStart(5);
	l2.insertStart(48);
	l2.insertStart(50);

	l3.insertOrder(3);
	l3.insertOrder(99);

	cout << "---------------L1---------------" << endl;
	cout << l1;

	cout << "---------------L2---------------" << endl;
	cout << l2;

	l1 += 100;
	cout << "---------------L1---------------" << endl;
	cout << l1;

	l1 += l3;
	cout << "---------------L1---------------" << endl;
	cout << l1;

	l3 += l2;
	l3--;
	cout << "---------------L3---------------" << endl;
	cout << l3;

	--l2;
	l2--;
	cout << "---------------L2---------------" << endl;
	cout << l2;

	l1.mixList(l2);
	l1.invertList();
	cout << "---------------L1---------------" << endl;
	cout << l1;

	return 0;
}