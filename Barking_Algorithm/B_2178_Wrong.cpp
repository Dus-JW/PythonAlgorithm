#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[502][502];

bool vis1[502][502];
bool vis2[502][502];

int dx1[4] = {0, 1, -1, 0};
int dy1[4] = {1, 0, 0, -1};

int dx2[4] = {1, 0, 0, -1};
int dy2[4] = {0, 1, -1, 0};

int	ft_BFS1(queue<pair<int,int> > &Q, int n, int m)
{
	int	route = 0;
	int	t = 0;
	while (!Q.empty())
	{
		int	dir;
		int nx,ny;
		pair<int,int> cur = Q.front();
		cout << "(" << cur.X << "," << cur.Y << ") ->";
		Q.pop();
		for (dir = t; dir < 4; dir++)
		{
			nx = cur.X + dx1[dir];
			ny = cur.Y + dy1[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue ;
			if (vis1[nx][ny] || board[nx][ny] != 1)
				continue ;
			vis1[nx][ny] = 1;
			Q.push(make_pair(nx,ny));
			break ;
		}
		if (dir == 4)
		{
			t++;
			vis1[nx][ny] = 0;
			Q.push(make_pair(nx,ny));
			route--;
			if (route == 0)
				return (0);
			continue;
		}
		t = 0;
		route++;
		if (nx == n - 1 && ny == m - 1)
			break ;
	}
	return (route);
}

int	ft_BFS2(queue<pair<int,int> > &Q, int n, int m)
{
	int	route = 0;
	int	t = 0;
	cout << '\n';
	while (!Q.empty())
	{
		int	dir;
		int nx,ny;
		pair<int,int> cur = Q.front();
		cout << "(" << cur.X << "," << cur.Y << ") ->";
		Q.pop();
		for (dir = t; dir < 4; dir++)
		{
			nx = cur.X + dx2[dir];
			ny = cur.Y + dy2[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue ;
			if (vis2[nx][ny] || board[nx][ny] != 1)
				continue ;
			vis2[nx][ny] = 1;
			Q.push(make_pair(nx,ny));
			break ;
		}
		if (dir == 4)
		{
			t++;
			vis2[nx][ny] = 0;
			Q.push(make_pair(nx,ny));
			route--;
			if (route == 0)
				return (0);
			continue;
		}
		t = 0;
		route++;
		if (nx == n - 1 && ny == m - 1)
			break ;
	}
	return (route);
}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int		n,m;
	int		ans1;
	int		ans2;
	string	s_num;
	queue<pair<int,int> > Q;
	
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> s_num;
		for (int j = 0; j < m; j++)
			board[i][j] = (int)(s_num[j] - '0');
	}
	Q.push(make_pair(0,0));
	vis1[0][0] = 1;
	ans1 = ft_BFS1(Q,n,m);

	Q.pop();
	Q.push(make_pair(0,0));
	vis2[0][0] = 1;
	ans2 = ft_BFS2(Q,n,m);
	if (ans1 == 0)
		cout << ans2 + 1;
	else if (ans2 == 0)
		cout << ans1 + 1;
	else
		(ans1 < ans2) ? cout << ans1 + 1 : cout << ans2 + 1;
	return (0);
}
