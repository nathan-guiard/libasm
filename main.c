#include "include/libasm.h"
#include <stdio.h>

int main()
{
	int i;
	char *str = 0;

	printf ("%p\n", str);
	i = ft_strlen(str);
	printf("res: %d\n", i);
	return (0);
}
