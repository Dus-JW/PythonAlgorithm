#include <bits/stdc++.h>
using namespace std;

int n,m;
int	board[1000002];
int	dist[1000002];

int	dx[2] = {-1,1};

void	ft_BFS(queue<int> &Q, int n, int m)
{
	if (n == m)
	{
		cout << 0 << endl;
		return ;
	}
	while (!Q.empty())
	{
		int cur = Q.front();
		Q.pop();
		for (int dir = 0; dir < 2; dir++)
		{
			int nx = cur + dx[dir];
			if (nx < 0 || nx >= 200000 || dist[nx] >= 1)
				continue;
			if (nx == m)
			{
				cout << dist[cur] + 1 << endl;
				return ;
			}
			dist[nx] = dist[cur] + 1;
			Q.push(nx);
		}
		if (cur < 0 || cur >= 200000 || dist[cur * 2] >= 1)
			continue;
		if ((cur * 2) == m)
		{
			cout << dist[cur] + 1 << endl;
			return ;
		}
		dist[cur * 2] = dist[cur] + 1;
		Q.push(cur * 2);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	queue<int> Q;
	Q.push(n);
	ft_BFS(Q,n,m);
	return (0);
}
