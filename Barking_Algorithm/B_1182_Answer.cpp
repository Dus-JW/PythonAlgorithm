#include<iostream>
using namespace std;

int n, s;
int cnt;
bool isused[22];
int arr[22];
int sum;

void func(int nx,int x)
{

	if (sum == s && nx != 0)		
	{
		for (int i = 0;i < n; i++)
		{
			cout << arr[i] << "-----" << sum << ' ';
		}
		cout <<'\n';
		cnt++;
	}

	for (int i = 0 ; i < n; i++)
	{
		if (isused[i] || x>i)
			continue ;
		isused[i] = true;
		sum += arr[i];
		func(nx + 1,i);

		isused[i] = false;
		sum -= arr[i];
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;
	for (int i = 0 ; i < n; i++)
		cin >> arr[i];

	func(0,0);

	cout << cnt;

	return 0;
}
