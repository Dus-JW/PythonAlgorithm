#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int		n;
	int		*arr;

	scanf("%d",&n);
	arr = (int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n ; i++)
		scanf("%d", &(arr[i]));
	
	free(arr);
	return (0);
}
