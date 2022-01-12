#include <bits/stdc++.h>
using namespace std;

# define X first
# define Y second

int			n,m;
string		board[1001];
string		dist[1001];
int			real_max;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void	ft_BFS(queue<pair<char,char> > &JQ, queue<pair<char,char> > &FQ, int n, int m)
{
	while (!FQ.empty())
	{
		pair<char,char> cur2 = FQ.front();
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
	}
	while (!JQ.empty())
	{
		pair<char,char> cur1 = JQ.front();
		JQ.pop();
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
	queue<pair<char,char> > JQ;
	queue<pair<char,char> > FQ;

	cin >> n >> m;
	getchar();
	for (int i = 0; i < n; i++)
	{
		getline(cin, board[i]);
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
	ft_BFS(JQ, FQ, n, m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (dist[i][j] == 0)
			{
				cout << "IMPOSSIBLE\n";
				return (0);
			}
			if (dist[i][j] > real_max)
				real_max = dist[i][j];
		}
	}
	cout << real_max - 1;
	return (0);
}
