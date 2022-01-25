#include <iostream>
#include <algorithm>
using namespace std;

int		n,s,m =5;
int		store[21];
int		arr[21];
bool	issued[21];

void func(int k)
{
	if (k == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return ;
	}

	for (int i = 0; i <= n; i++)
	{
		if (!(issued[i]))
		{
			arr[k] = store[i];
			issued[i] = 1;
			if (k == 0 || arr[k - 1] < i)
				func(k+1);
			issued[i] = 0;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;
	getchar();
	for (int i = 0; i < n; i++)
		cin >> store[i];
	func(0);
	return (0);
}
