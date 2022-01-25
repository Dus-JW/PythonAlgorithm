#include <iostream>
#include <algorithm>
using namespace std;

int		n,s,t;
int		store[21];
int		arr[21];
bool	isused[21];

void func(int k)
{
	cout << "k == " << k << endl;
	if (k == n)
	{
		return ;
	}
	for (int i = t; i < k; i++)
	{
		isused[i] = 1;
		if (!isused[k])
			func(k + 1);
		cout << store[i] << " ";
		isused[k] = 0;
	}
	cout << '\n';
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> store[i];
	func(1);
	return (0);
}
