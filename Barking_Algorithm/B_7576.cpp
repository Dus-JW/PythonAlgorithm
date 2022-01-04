#include <bits/stdc++.h>
using namespace std;

# define X first
# define Y second

int n,m;
int board[1002][1002];
int dist[1002][1002];

int	q_zero = 0;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int ft_BFS(queue<pair<int,int> &Q, int n, int m)
{
	int	count = 0;
	while (!Q.empty())
	{
		pair<int,int> cur = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + du[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue ;
			if (dist[nx][ny] >= 1 || board[nx][ny] == -1)
				continue ;
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			Q.push(make_pair(nx,ny));
		}
		if (dir == 4)
			break;
		count++;
	}
	return (count);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	queue<pair<int,int> > Q;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 0)
			{
				Q.push(make_pair(i,j));
				int cnt = ft_BFS(Q,n,m);
				if (cnt == 0)
				{
					cout << -1;
					return (0);
				}
				q_zero++;
			}
			else if (board[i][j] == 1)
			{
				Q.push(make_pair(i,j);
			}
		}
	}
	if (q_zero == 0)
	{
		cout << 0;
		return (0);
	}
}
