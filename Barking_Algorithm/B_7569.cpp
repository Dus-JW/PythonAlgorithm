#include <iostream>
#include <tuple>
#include <queue>
using namespace std;

int n,m,h;
int board[1002][1002][1002];
int dist[1002][1002][1002];

int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

void	ft_BFS(queue<tuple<int,int,int> > &Q, int h, int n, int m)
{
	int	dir;

	while (!Q.empty())
	{
		tuple<int,int,int> cur = Q.front();
		Q.pop();
		for (dir = 0; dir < 6; dir++)
		{
			int	nx = get<0>(cur) + dx[dir];
			int	ny = get<1>(cur) + dy[dir];
			int	nz = get<2>(cur) + dz[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h)
				continue ;
			if (dist[nx][ny][nz] >= 0)
				continue ;
			dist[nx][ny][nz] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
			Q.push(make_tuple(nx,ny,nz));
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int	count = 0;
	queue<tuple<int,int,int> > Q;
	cin >> m >> n >> h;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				cin >> board[i][j][k];
				if (board[i][j][k] == 1)
					Q.push(make_tuple(i,j,k));
				else if (board[i][j][k] == 0)
					dist[i][j][k] = -1;
			}
		}
	}
	ft_BFS(Q,h,n,m);
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				if (dist[i][j][k] == -1)
				{
					cout << -1;
					return (0);
				}
				count = max(count, dist[i][j][k]);
			}
		}
	}
	cout << count;
	return (0);
}
