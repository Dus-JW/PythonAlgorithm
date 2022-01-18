#include <bits/stdc++.h>
using namespace std;

int		dx[4] = {0,0,1,1};
int		dy[4] = {0,1,0,1};
int		cnt = 0;

void	Z_recursive(int **dist,int j, int k, int n)
{
	if (n == 1)
	{
		for (int i = 0; i < 4; i++)
		{
			dist[dx[i] + j][dy[i] + k] = cnt;
			cnt++;
		}
		return ;
	}
	for (int i = 0; i < 4; i++)
		Z_recursive(dist, j + dx[i] * (1<<(n -1)), k + dy[i] * (1<<(n-1)), n - 1);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int	n,r,c;

	cin >> n >> r >> c;
	int **dist = new int*[1<<n];
	for (int i = 0; i < 1<<n; i++)
		dist[i] = new int[1<<n];
	Z_recursive(dist,0,0,n);
	cout << dist[r][c];
	for (int i = 0; i< 1<<n; i++)
		delete [] dist[i];
	delete [] dist;
	return (0);
}
