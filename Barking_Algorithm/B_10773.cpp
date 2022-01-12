#include <bits/stdc++.h>
using namespace std;

int	scount;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k;
	cin >> k;
	stack<int> S;
	for (int i = 0; i < k; i++)
	{
		int n;
		cin >> n;
		if (n == 0)
			S.pop();
		else
			S.push(n);
	}
	int len = S.size();
	for (int i = 0; i < len; i++)
	{
		scount += S.top();
		S.pop();
	}
	cout << scount;
	return (0);
}
