#include <stdio.h>

int main(void)
{
	/* 0000 1001  */
	unsigned int x = 9;
	printf("%u\n", x);

	unsigned int a = x >> 1;
	printf("%u\n", a);

	unsigned int b = x >> 2;
	printf("%u\n", b);

	unsigned int c = x >> 3;
	printf("%u\n", c);

	unsigned int d = x >> 20;
	printf("%u\n", d);

	unsigned int e = ~x;
	printf("%u\n", e);


	//printf("%li", sizeof(x));


}
