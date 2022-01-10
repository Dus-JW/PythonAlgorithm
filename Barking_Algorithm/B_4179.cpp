#include <bits/stdc++.h>
using namespace std;

# define X first
# define Y second

int		n,m;
string	board[1001][1001];
string	dist[1001][1001];

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


void	ft_BFS(queue<pair<int,int> > &JQ, queue<pair<int,int> > &FQ, int n, int m)
{
	int	count = 0;

	while (!JQ.empty())
	{
		pair<int,int> cur1 = JQ.front();
		pair<int,int> cur2 = FQ.front();
		JQ.pop();
		FQ.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur2.X + dx[dir];
			int ny = cur2.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue ;
			if (dist[nx][ny] >= 1 || dist[nx][ny] == -1)
				continue ;
			dist[nx][ny] = dist[cur2.X][cur2.Y] + 1;
			FQ.push(make_pair(nx,ny));
		}
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur1.X + dx[dir];
			int ny = cur1.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (dist[nx][ny] >= 1 || dist[nx][ny] == -1)
				continue;
			dist[nx][ny] = dist[cur1.X][cur1.Y] + 1;
			JQ.push(make_pair(nx,ny));
		}
	}
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
		cin.getline(board[i]);
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 'J')
			{
				dist[i][j] = 1;
				JQ.push(make_pair(i,j));
			}
			else if (board[i][j] == 'F')
			{
				dist[i][j] = 1;
				FQ.push(make_pair(i,j));
			}
			else if (board[i][j] == '.')
			{
				dist[i][j] = 0;
			}
			else if (board[i][j] == '#')
			{
				dist[i][j] = -1;
			}
		}
	}
	ft_dist_print();
	ft_BFS(JQ, FQ, n, m);
	ft_dist_print();
	return (0);
}
