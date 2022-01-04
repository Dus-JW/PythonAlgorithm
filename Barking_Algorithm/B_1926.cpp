#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[502][502]; 
bool vis[502][502];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int	ft_BFS(queue<pair<int,int> > &Q, int n, int m)
{
	int	area = 0;
	while (!Q.empty())
	{
		pair<int,int> cur = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue ;
			if (vis[nx][ny] || board[nx][ny] != 1)
				continue ;
			vis[nx][ny] = 1;
			Q.push(make_pair(nx,ny));
		}
		area++;
	}
	return (area);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	int max = 0;
	int	count = 0;
	int area;

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	}
	queue<pair<int,int> > Q;
	for (int i = 0; i < n; i++)
	{
		for (int j =0; j< m; j++)
		{
			if (!vis[i][j] && board[i][j] == 1)
			{
				Q.push(make_pair(i,j));
				vis[i][j] = 1;
				area = ft_BFS(Q,n,m);
				count++;
				if (area > max)
					max = area;
			}
		}
	}
	cout << count << '\n' << max;
	return (0);
}
