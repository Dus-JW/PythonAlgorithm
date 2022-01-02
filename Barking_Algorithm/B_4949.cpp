#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[MX + 1];
int	s_size = 0;

void	ft_push(int data)
{
	dat[s_size++] = data;
}

void	ft_pop()
{
	if (s_size == 0)
		return ;
	s_size--;
}

int	main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string	text;

	while (1)
	{
		getline(cin, text);
		if (text == ".")
			break ;
		s_size = 0;
		for (int i = 0; i < text.length(); i++)
		{
			if (text[i] == '(')
				ft_push('(');
			else if (text[i] == '[')
				ft_push('[');
			else if (text[i] == ')')
			{
				if (dat[s_size - 1] == '(')
					ft_pop();
				else
				{
					s_size = -1;
					break ;
				}
			}
			else if (text[i] == ']')
			{
				if (dat[s_size - 1] == '[')
					ft_pop();
				else
				{
					s_size = -1;
					break ;
				}
			}
		}
		if (s_size == 0)
			cout << "yes\n";
		else
			cout << "no\n";	
	}
	return (0);
}
