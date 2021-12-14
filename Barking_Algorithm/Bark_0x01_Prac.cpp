#include <iostream>
using namespace std;

int	func2(int arr[], int N);
/*
int	func2(int arr[], int N)
{	
	int	numbase[101] = {0,};
	for (int e = 0; e < N; e++)
		numbase[arr[e]]++;
	for (int i = 0; i < 50; i++)
	{
		if (numbase[i] + numbase[100 - i] == 2)
			return (1);
	}
	return (0);
}
*/

// My Code
// This can be more easliy to do
// My Code O(N + 50)
// Answer O(N)

int	func2(int arr[], int N)
{
	int occur[101] = {};
	for (int i = 0; i < N; i++)
	{
		if (occur[100 - arr[i]] == 1)
			return (1);
		occur[arr[i]] = 1;
	}
	return (0);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int		n;
	int		numb[101] = {};

	numb[0] = 1;
	numb[1] = 52;
	numb[2] = 48;
	n = func2(numb, 3);
	cout << n;
	return (0);
}
