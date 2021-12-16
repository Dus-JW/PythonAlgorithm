#include <iostream>
using namespace std;

typedef struct sNode
{
	struct sNode	*prev;
	struct sNode	*next;
	int				data;
} tNode;

int main(void)
{
	tNode a,b;
	a.next = &b;
	a.data = 10;
	b.data = 20;
	cout << a.data << (a.next)->data << endl;
	return (0);
}
