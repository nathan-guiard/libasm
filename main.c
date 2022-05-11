#include "libasm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main()
{
	char str[10];

	int ret = ft_read(0, str, 10);
	printf("%s\n%d", str, ret);
}
