#include <bits/stdc++.h>
using namespace std;

int	cnt = 1;

void hanoi(int a, int b, int c, int n)
{
	if (n == 0)
		return ;
	hanoi(a,c,b,n/2);
	cout << a << " " << c << "\n";
	hanoi(b,a,c,n/2);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int	n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cnt *= 2;
	}
	cout << cnt - 1<< "\n";
	hanoi(1,2,3,cnt - 1);
	return (0);
}
