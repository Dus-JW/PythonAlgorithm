#include <iostream>
#include "LinkedList.h"

using namespace std;

int main(void)
{
	tlist a,b;
	a.data = 5;
	a.next = &b;
	b.data = 10;
	cout << a.data << ' ' << a.next->data << endl;
	return (0);
}
