#include <bits/stdc++.h>
using namespace std;

void	ft_push(int *arr, int &hei, int val)
{
	arr[hei] = val;
	hei++;
}

void	ft_pop(int *arr, int &hei)
{
	if (hei == 0)
	{
		cout << -1 << endl;
		return ;
	}
	cout << arr[hei - 1] << endl;
	arr[hei - 1] = -1;
	hei--;
}

void	ft_top(int *arr, int &hei)
{
	if (hei == 0)
	{
		cout << -1 << endl;
		return ;
	}
	cout << arr[hei - 1] << endl;
}

int	ft_change(string opt)
{
	if (opt == "push")
		return (1);
	else if (opt == "pop")
		return (2);
	else if (opt == "size")
		return (3);
	else if (opt == "empty")
		return (4);
	else if (opt == "top")
		return (5);
	else
		opt = "";
	return (0);
}

int main(void)
{
	int				n;
	int				tmp = 0;
	int				val = 0;
	int				hei = 0;
	string			opt;
	int				n_stack[10000] = {0, };

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> opt;
		tmp = ft_change(opt);
		if (tmp == 1)
		{
			cin >> val;
			ft_push(n_stack, hei, val);
		}
		else if (tmp == 2)
			ft_pop(n_stack, hei);
		else if (tmp == 3)
			cout << hei << endl;
		else if (tmp == 4)
		{
			if (hei == 0)
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
		else if (tmp == 5)
			ft_top(n_stack, hei);
	}
	return (0);
}
