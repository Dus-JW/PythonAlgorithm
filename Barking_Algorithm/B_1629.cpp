#include <bits/stdc++.h>
using namespace std;

int recursive(int a, int b, int c)
{
	cout << a <<"  " << b << "  " << a % c << endl;
	if (b == 1)
		return (a % c);
	long long val = recursive(a, b/2, c);
	cout << "first val == " << val << endl;
	val = val * val % c;
	cout << "second val == " << val << endl;
	cout << "it's return value == " << val * a % c << endl;
	cout << "b is == " << b << endl;
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
