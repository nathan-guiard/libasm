#include "include/libasm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int i;
	char	*dest = strdup("aaaaaaaaaaaa");
	char	*src = NULL;

	ft_strcpy(dest, src);
	printf("%s\n", dest);
}
