#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	queue<int>	Q;
	int			n;
	int			val;
	string		opt;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> opt;
		if (opt == "push")
		{
			cin >> val;
			Q.push(val);
		}
		else if (opt == "front")
			cout << Q.front() << endl;
		else if (opt == "back")
			cout << Q.back() << endl;
		else if (opt == "size")
			cout << Q.size() << endl;
		else if (opt == "empty")
			cout << Q.empty() << endl;
		else if (opt == "pop")
		{
			cout << Q.front() << endl;
			Q.pop();
		}
	}
	return (0);
}
