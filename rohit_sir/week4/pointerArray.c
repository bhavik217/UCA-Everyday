// Pointer on array
#include <stdio.h>

int main() {
	
	int arr[] = {1, 2, 4, 5, 6};

	int *ptr = arr;
	
	for(int i=0; i<=5; i++){
		printf("%d ", *(arr + i));
	}
}
// Why sometimes segmentation fault ocuurs and sometimes not?