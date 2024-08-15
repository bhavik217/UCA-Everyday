#include <stdio.h>
#include <stdlib.h>
#include "bubble.h"

int b_search(int arr[], int n, int k){
	int l=0, h=n-1;
	while(l <= h){
		int mid = l + (h-l)/2;
		if(arr[mid] == k){
			return 1;
		}
		else if(arr[mid] < k){
			l = mid+1;
		}
		else h = mid-1;
	}
	return 0;
}

int main(){
	int n;
	scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));
	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}

	int k;
	scanf("%d", &k);

	b_sort(arr, n);
	
	if(b_search(arr, n, k)) printf("Found");
	else printf("Not Found");
}
