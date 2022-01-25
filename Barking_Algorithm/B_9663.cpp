#include <iostream>
#include <algorithm>
using namespace std;

int		n;
int		cnt;
int		arr[31][31];
bool	issued[31][31];
bool	i_visit[31][31];
int		dist1[4] = {-1, 1, -1 ,1};
int		dist2[4] = {-1, -1, 1, 1};
bool	find_wrong = false;

bool	is_possible_col_row(int col)
{
	for (int i = 0; i < n; i++)
	{
		if (issued[col][i] == 1 || issued[i][col] == 1)
			return (false);
	}
	return (true);
}

bool	is_possible_diag(int row, int col)
{
	if (i_visit[row][col] == 1 || row > n || row < 0 || col > n || col < 0)
		return (false);
	else
	{
		for (int i = 0; i < 4; i++)
		{
			if (issued[row + dist1[i]][col + dist2[i]] == 1)
			{
				find_wrong = false;
				return (false);
			}
			else
			{
				i_visit[row][col] = 1;	
				is_possible_diag(row + dist1[i], col + dist2[i]);
			}
		}
	}
	if (find_wrong == false)
		return (false);
	else
		return (true);
}

void	func(int k)
{
	for (int t1 = 0; t1 < 31; t1++)
	{
		for (int t2 = 0; t2 < 31; t2++)
			i_visit[t1][t2] = 0;
	}
	cout << k << endl;
	if (k == n)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << arr[i][j] << ' ';
			}
			cout << '\n';
		}
		cout << "-------\n"; 
		cnt++;
		return ;
	}
	for (int i = k ; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			find_wrong = true;
			if (is_possible_col_row(j) && is_possible_diag(i,j))
			{
				cout << i << ' ' << j << " : " << k << endl;
				arr[i][j] = 1;
				issued[i][j] = 1;
				for (int i = 0; i < n; i++)
				{
					for (int j = 0; j < n; j++)
					{
						cout << arr[i][j] << ' ';
					}
					cout << '\n';
				}
				cout << "-------\n";
				func(k + 1);
				issued[i][j] = 0;
			}
			for (int t1 = 0; t1 < 31; t1++)
			{
				for (int t2 = 0; t2 < 31; t2++)
					i_visit[t1][t2] = 0;
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	func(0);
	return (0);
}
