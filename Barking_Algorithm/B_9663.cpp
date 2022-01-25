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

bool	is_possible_diag(int col, int row, int x)
{
	int d1,d2;
	for (int i = 0; i < 4; i++)
	{
		d1 = dist1[i];
		d2 = dist2[i];
		for (int j = 0; j < n; j++)
		{
			cout << "col : " << col << ", row :" << row << "it 's d1 d2 :" << d1 << ' ' << d2 << endl;
			if (col + d1 > n || col + d1 < 0 || row + d2 > n || row + d2 < 0)
				break ;
			else if (issued[col+ d1][row + d2] == 1)
			{
				find_wrong = false;
				return (false);
			}
			else
			{
				d1 += dist1[i];
				d2 += dist2[i];
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
	for (int j = 0; j < n; j++)
	{
		cout << "---------------" << k << ' ' << j << "------------------\n"; 
		find_wrong = true;
		if (is_possible_col_row(j) && is_possible_diag(k,j,0))
		{
			cout << k << ' ' << j << " : " << k << endl;
			arr[k][j] = 1;
			issued[k][j] = 1;
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
			arr[k][j] = 0;
			issued[k][j] = 0;
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
