#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	queue<int> Q;
	Q.push(10);
	Q.push(30);
	Q.push(50);
	cout << Q.size() << '\n';
	if (Q.empty())
		cout << "Q is empty\n";
	else
		cout << "Q is not empty\n";
	Q.pop();
	cout << Q.front() << '\n';
	cout << Q.back() << '\n';
	Q.push(60);
	Q.pop();
	cout << Q.front() << '\n';
	return (0);
}
