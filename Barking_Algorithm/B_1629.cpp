#include <bits/stdc++.h>
using namespace std;

int recursive(int a, int b, int c)
{
	if (b == 1)
		return (a % c);
	long long val = recursive(a, b/2, c);
	val = val * val % c;
	if (b%2==0) return (val);
	return (val * a % c);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long a,b,c;
	cin >> a >> b >> c;
	cout << recursive(a,b,c);
	return (0);
}
