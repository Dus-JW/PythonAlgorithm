#include <bits/stdc++.h>
using namespace std;

void	BackTracking(int n, int m, stack<int> &S)
{
	int	k[8] = {0,};

	while (!S.empty())
	{
		int a = S.top();
		int	r_a = a;
		S.pop();
		k[0] = a;
		cout << a << ' ';
		for (int i = 1; i < m; i++)
		{
			k[i] += 1;
			cout << k[i] << ' ';
		}
		if (k[m - 1] < n)
			S.push(r_a);
		else
		{
			for (int i = 0; i < m; i++)
				k[i] = 0;
		}
		cout << '\n';
	}
	return ;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int	n,m;

	cin >> n >> m;
	stack<int> S;
	for (int i = n; i > 0; i--)
		S.push(i);
	BackTracking(n,m,S);
	return (0);
}
