#include <stdio.h>
#define MAX 100

typedef int keytype;
typedef float othertype;

typedef struct{
	keytype key;
	othertype other;
}recordtype;

void swap(recordtype *x, recordtype *y){
	recordtype temp = *x;
	*x = *y;
	*y = temp;
}

void read_data(recordtype a[], int *n){
	FILE *f;
	f = fopen("data_2.txt", "r");
	int i=0;
	if(f!=NULL)
		while(!feof(f)){
			fscanf(f,"%d%f", &a[i].key, &a[i].other);
			i++;
		}
	else printf("ERORR\n");	
	fclose(f);
	*n=i;
}

void print_data(recordtype a[], int n){
	int i;
	for(i=0; i<n; i++)
		printf("%3d%5d%8.2f\n", i+1, a[i].key, a[i].other);
	
}

int partition(recordtype a[], int low, int high) {
    int pivot = a[low].key;
    int L = low + 1;
    int R = high;
  	while(L<=R){
  		while(L<=R && a[L].key <= pivot)
			L++;
		while(L<=R && a[R].key >= pivot)
			R--;
		if(L<R) 
			swap(&a[L], &a[R]);
	  }
    swap(&a[R], &a[low]);
    return R;
}


void quick_sort_variant(recordtype arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quick_sort_variant(arr, low, pivot - 1);
        quick_sort_variant(arr, pivot + 1, high);
    }
}


int main(){
	int n,i;
	recordtype a[MAX];
	printf("Selection Sort Algorithm\n\n");
	read_data(a, &n);
	printf("Before sorting:\n");
	print_data(a, n);
	quick_sort_variant(a, 0, n-1);
	printf("After sorting:\n");
	print_data(a, n);
	return 0;
}
