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

void	sudoku(int k)

	int t = 0;
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
		cout << "--------------------\n";
		return ;
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = k; j < 9; j++)
		{
			if (!isused[i][j])
			{
				cout << i << ' ' << j << '\n';
				board[i][j] = k + 1;
				isused[k][i] = true;
				if (is_right(k,i))
					sudoku(k + 1);
				board[k][i] = 0;
				isused[k][i] = false;
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
	sudoku(0);
	return (0);
}
