#include <bits/stdc++.h>
using namespace std;

int		board[9][9];
bool	isused[9][9];

bool	is_right(int col, int row)
{
	for (int i = 0; i < 9; i++)
	{
		if (row == i)
			continue ;
		else if (board[col][i] == board[col][row])
			return (false);
	}
	for (int i = 0; i < 9; i++)
	{
		if (col == i)
			continue ;
		else if (board[i][row] == board[col][row])
			return (false);
	}
	return (true);
}

bool	is_not_remain(int k)
{
	for (int i = 0; i < 9; i++)
	{
		if (!isused[k][i])
			return (false);
	}
	return (true);
}

void	sudoku(int k)
{
	if (k == 9)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cout << board[i][j] << ' ';
			}
			cout << '\n';
		}
		return ;
	}
	for (int i = 0; i < 9; i++)
	{
		if (!isused[k][i])
		{
			for (int j = 1; j < 10; j++)
			{
				board[k][i] = j;
				isused[k][i] = true;
				if (is_right(k,i) && is_not_remain(k))
					sudoku(k + 1);
				else if (is_right(k,i) && !(is_not_remain(k)))
					break ;
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> board[i][j];
			if (board[i][j] != 0)
				isused[i][j] = true;
		}
	}
	cout << "\n\n";
	sudoku(0);
	return (0);
}
