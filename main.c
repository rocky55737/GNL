#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int fd, cnt;
	char *ret;

	fd = open("testfile", O_RDONLY);
	cnt = 0;
	while (cnt < 10)
	{
		ret = get_next_line(fd);
		printf("%d번째 트라이 : %s\n", cnt, ret);
		cnt ++;
	}
}
