#include <stdio.h>
#define MAX 100

void swap(int *x, int *y){
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void insertion_sort(int a[], int n) {
    int i,j;
    for (i = 1; i <= n-1; i++){
    	j=i;
    	while(j>0 && a[j] < a[j-1]){
    		swap(&a[j], &a[j-1]);
    		j--;
		}
	}
     
}

int main(){
	int n,i;
	scanf("%d", &n);
	int a[MAX];
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);
	insertion_sort(a, n);
	for(i=0; i<n; i++)
		printf("%d ",a[i]);
	
	return 0;
}
