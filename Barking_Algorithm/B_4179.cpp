#include <bits/stdc++.h>
using namespace std;

# define X first
# define Y second

int			n,m;
string		board[1001];
int			dist1[1001][1001];
int			dist2[1001][1001];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int	ft_BFS(queue<pair<int,int> > &JQ, queue<pair<int,int> > &FQ, int n, int m)
{
	while (!FQ.empty())
	{
		pair<int,int> cur = FQ.front();
		FQ.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue ;
            if (dist1[nx][ny] >= 0 || board[nx][ny] == '#')
                continue ; 
            dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
            FQ.push(make_pair(nx,ny));
		}
	}
	while (!JQ.empty())
	{
		pair<int,int> cur = JQ.front();
		JQ.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
			{
				cout << dist2[cur.X][cur.Y] + 1;
				return (-1);
			}
			if (dist2[nx][ny] >= 0 || board[nx][ny] == '#')
				continue;
			if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.X][cur.Y] + 1)
				continue;
			dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
			JQ.push(make_pair(nx,ny));
		}
	}
	return (0);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	queue<pair<int,int> > JQ;
	queue<pair<int,int> > FQ;

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		fill(dist1[i], dist1[i] + m, -1);
		fill(dist2[i], dist2[i] + m, -1);
	}
	for (int i = 0; i < n; i++)
		cin >> board[i];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 'F')
			{
				FQ.push(make_pair(i,j));
				dist1[i][j] = 0;
			}
			if (board[i][j] == 'J')
			{
				JQ.push(make_pair(i,j));
				dist2[i][j] = 0;
			}
		}
	}
	if (ft_BFS(JQ, FQ, n, m) == -1)
		return (0);
	cout << "IMPOSSIBLE\n";
	return (0);
}
