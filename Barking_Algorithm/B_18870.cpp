#include <iostream>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int		n;
	cin >> n;
	int		arr[n];
	int		ans[1000000] = {0,};
	for (int i = 0; i<n; i++)
		cin >> arr[i];
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
		{
			if (arr[i] > arr[j])
			{
				ans[i]++;
			}
		}
	}
	for (int i = 0; i<n; i++)
	{
		cout << ans[i] << ' ';
	}
	return (0);
}
