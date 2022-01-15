#include <stdio.h>

void des(char *arr);

int main(void)
{
	char arr[10] = "Carh wwd";

	des(arr);
	return (0);
}


void des(char *arr)
{
	char tmp;
	int i = 1, j = 3;
	tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
	for (int i = 0; i < 8; i++)
	{
		printf("%c ", arr[i]);
	}
}
