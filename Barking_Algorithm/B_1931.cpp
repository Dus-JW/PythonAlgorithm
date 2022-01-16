#include <bits/stdc++.h>
using namespace std;

# define X first
# define Y second

vector<pair<int,int> > arr;

bool	cmp(pair<int,int> f, pair<int,int> s)
{
	if (f.Y == s.Y)
		return (f.X < s.X);
	else
		return (f.Y < s.Y);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int	n;
	int	a_count = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a,b;
		cin >> a >> b;
		arr.push_back(make_pair(a,b));
	}
	sort(arr.begin(), arr.end(), cmp);
	int t = 0;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i].X << " " << arr[i].Y << endl;
		if (t <= arr[i].X)
		{
			t = arr[i].Y;
			a_count++;
		}
	}
	cout << a_count;
	return (0);
}
