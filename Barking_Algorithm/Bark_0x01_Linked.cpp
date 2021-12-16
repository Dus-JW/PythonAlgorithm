#include <iostream>
using namespace std;

typedef struct sNode
{
	struct sNode    *prev;
	struct sNode    *next;
	int             data;
} tNode;

void	ft_erase(tNode &tlist, int ans)
{
	int		i;

	i = 0;
	while (1)
	{
		if (tlist.data == ans)
		{
			i = 1;
			break ;
		}
		tlist = *(tlist.next);
	}
	if (i == 1)
	{
		tlist.prev = tlist.next;
		(tlist.next)->prev = tlist.prev;
	}
}

int main(void)
{
	tNode a,b,c;
	a.next = &b;
	b.prev = &a;
	b.next = &c;
	c.prev = &b;
	c.next = NULL;
	a.data = 10;
	b.data = 20;
	c.data = 30;

	cout << a.data << ' ' << (a.next)->data << ' ' << (b.next)->data << endl;
	ft_erase(a, 20);
	cout << (a.next)->data << endl;
	return (0);
}
