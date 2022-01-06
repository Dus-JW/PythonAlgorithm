#include <bits/stdc++.h>
using namespace std;

# define X first
# define Y second

int n,m;
int board[1002][1002];
int dist[1002][1002];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void	ft_dist_print()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << dist[i][j] << " ";
		}
		cout << '\n';
	}
}

void	ft_BFS(queue<pair<int,int> > &Q, int n, int m)
{
	int	count = 0;
	int	dir;

	while (!Q.empty())
	{
		pair<int,int> cur = Q.front();
		Q.pop();
		for (dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue ;
			if (dist[nx][ny] >= 0)
				continue ;
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			Q.push(make_pair(nx,ny));
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int	count = 0;
	queue<pair<int,int> > Q;
	cin >> m >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 1)
				Q.push(make_pair(i,j));
			else if (board[i][j] == 0)
				dist[i][j] = -1;
		}
	}
	ft_dist_print();
	ft_BFS(Q,n,m);
	ft_dist_print();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (dist[i][j] == -1)
			{
				cout << -1;
				return (0);
			}
			count = max(count, dist[i][j]);
		}
	}
	cout << count;
	return (0);
}
