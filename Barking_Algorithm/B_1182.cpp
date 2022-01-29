#include <bits/stdc++.h>
using namespace std;

int		n,s,m = 1;
int		t;
int		cnt;
int		arr[22];
int		store[22];
bool	issued[22];
long long		s_cnt;
void func(int k, int k2)
{
	if (k == m)
	{
		int total = 0;
		for (int i = 0; i < m; i++)
		{
			cout << store[i] << ' ';
			total += store[i];
		}
		cout << '\n';
		s_cnt++;
		if (total == s)
		{
			cnt++;
		}
		return ;
	}

	for (int i = 0; i < n; i++)
	{
		t = i;
		if (!(issued[i]))
		{
			store[k] = arr[i];
			issued[i] = 1;
			if (k == 0 || k2 < i)
				func(k+1 , t);
			issued[i] = 0;
		}
	}
	if (m < n && store[0] == arr[t])
	{
		for (int i = 0; i < n; i++)
			issued[i] = 0;
		m++;
		k = 0;
		func(k, 0);
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
	func(0, 0);
	cout << cnt << '\n';
	cout << s_cnt << '\n';
	return (0);
}
