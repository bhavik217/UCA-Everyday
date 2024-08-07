// Testing pointer in c
#include <stdio.h>

int main(void) {

	unsigned int a = 255;

	int *b = &a;
	unsigned char *c = &a;

	printf("%d\n", *b);
	printf("%d\n", *c);
}
// Why unsigned char works fine on 255 but signed char failed?