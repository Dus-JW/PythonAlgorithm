#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[2*MX+1];
int head = MX, tail = MX;
int d_size = 0;

void push_front(int x){
	dat[--head] = x;
	d_size++;
}

void push_back(int x){
	dat[tail++] = x;
	d_size++;
}

void pop_front(){
	if (head == tail)
	{
		cout << -1 << '\n';
		return ;
	}
	cout << dat[head] << '\n';
	head++;
	d_size--;
}

void pop_back(){
	if (head == tail)
	{
		cout << -1 << '\n';
		return ;
	}
	cout << dat[tail - 1] << '\n';
	tail--;
	d_size--;
}

int front(){
	if (head == tail)
	{
		return (-1);
	}
	return (dat[head]);
}

int back(){
	if (head == tail)
	{
		return (-1);
	}
	return (dat[tail - 1]);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int		n;
	int		num;
	string	opt;

	cin >> n;
	for (int i = 0; i < n ; i++)
	{
		cin >> opt;
		if (opt == "push_front")
		{
			cin >> num;
			push_front(num);
		}
		else if (opt == "push_back")
		{
			cin >> num;
			push_back(num);
		}
		else if (opt == "pop_front")
		{
			pop_front();
		}
		else if (opt == "pop_back")
		{
			pop_back();
		}
		else if (opt == "size")
		{
			cout << d_size << '\n';
		}
		else if (opt == "empty")
		{
			if (d_size == 0)
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (opt == "front")
		{
			cout << front() << '\n';
		}
		else if (opt == "back")
		{
			cout << back() << '\n';
		}
	}
	return (0);
}
