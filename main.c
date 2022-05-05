#include "include/libasm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int i;
	char	*dest = strdup("aaa");
	char	*src = strdup("aaa");

	i = ft_strcmp(dest, src);
	printf("%d\n", i);
}
