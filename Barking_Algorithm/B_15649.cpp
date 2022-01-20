#include <bits/stdc++.h>
using namespace std;

void	BackTracking(int n, int m, int k)
{
	if (m == 0)
		return ;
	int t;
	for (int i = 1; i < n + 1; i++)
	{
		cout << i << ' ';
		t = m;
		BackTracking(n,m-1,k+1);
		m = t;
		cout << '\n';
		if (k++ < n)
			continue;
	}
	return ;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,h;

	cin >> n >> m;
	BackTracking(n,m,1);
	return (0);
}
