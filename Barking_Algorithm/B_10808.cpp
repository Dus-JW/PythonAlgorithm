#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string	name;
	int		alpha[26]={0,};

	cin >> name;
	for (int e : name)
		alpha[-('a' - e)] += 1;
	for (int i : alpha)
		cout << i << ' ';
	return (0);
}
