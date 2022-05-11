#include "libasm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main()
{
	printf ("\n\n%ld\n", ft_write(0, "Hello world!\n", 13));
	printf("|%d|", errno);
}
