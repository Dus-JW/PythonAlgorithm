#include <bits/stdc++.h>
using namespace std;

int	t;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		stack<char> S;
		string arr;
		cin >> arr;
		for (int j = 0; j < arr.length(); j++)
		{
			if (arr[j] == '(')
				S.push('(');
			else if (arr[j] == ')')
			{
				if (S.size() == 0)
				{
					S.push(')');
					break ;
				}
				if (S.top() != '(')
				{
					cout << "NO\n";
					break ;
				}
				else
					S.pop();
			}
		}
		if (S.size() != 0)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
	return (0);
}
