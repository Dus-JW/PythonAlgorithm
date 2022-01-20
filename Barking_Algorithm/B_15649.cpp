#include <bits/stdc++.h>
using namespace std;

int	k = 1;

void	BackTracking(int n, int m, int h)
{
	cout << h << ' ';
	if (m <= 1)
	{
		cout << '\n';
		return ;
	}
	BackTracking(n,m-1,k);
	return ;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,h;

	cin >> n >> m;
	h = 1;
	for (int i = 1; i < n + 1; i++)
	{
		BackTracking(n,m,i);
		if (k < n)
		{
			k++;
			i--;
			continue ;
		}
		else
			k = 1;
	}
	return (0);
}
