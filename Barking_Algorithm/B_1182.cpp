#include <iostream>
#include <algorithm>
using namespace std;

int		n,s,m = 1;
int		t;
int		arr[21];
int		store[21];
bool	issued[21];

void func(int k)
{
	if (k == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << store[i] << ' ';
		}
		cout << '\n';
		return ;
	}

	for (int i = 0; i < n; i++)
	{
		t = i;
		if (!(issued[i]))
		{
			store[k] = arr[i];
			issued[i] = 1;
			if (k == 0 || arr[k - 1] < arr[i])
				func(k+1);
			issued[i] = 0;
		}
	}
	if (m < n && store[0] == arr[t])
	{
		for (int i = 0; i < n; i++)
			issued[i] = 0;
		m++;
		k = 0;
		func(k);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;
	getchar();
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	func(0);
	return (0);
}
