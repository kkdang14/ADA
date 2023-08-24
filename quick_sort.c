#include <stdio.h>
#define MAX 100

void swap(int *x, int *y){
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int partition(int a[], int low, int high) {
    int pivot = a[low];
    int L = low + 1;
    int R = high;
  	while(L<=R){
  		while(L<=R && a[L] <= pivot)
			L++;
		while(L<=R && a[R] >= pivot)
			R--;
		if(L<R) 
			swap(&a[L], &a[R]);
	  }
    swap(&a[R], &a[low]);
    return R;
}


void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quick_sort(arr, low, pivot - 1);
        quick_sort(arr, pivot + 1, high);
    }
}


int main(){
	int n,i;
	scanf("%d", &n);
	int a[MAX];
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);
	quick_sort(a, 0, n-1);
	for(i=0; i<n; i++)
		printf("%d ",a[i]);
	
	return 0;
}
