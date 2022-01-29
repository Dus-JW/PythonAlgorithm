#include <bits/stdc++.h>
using namespace std;

int		n,s,m = 1;
int		t;
int		cnt;
int		arr[21];
int		store[21];
bool	issued[21];

void func(int k)
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
			if (k == 0 || store[k - 1] < store[k])
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
	sort(arr, arr + n);
	func(0);
	cout << cnt << '\n';
	return (0);
}
