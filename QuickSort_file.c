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

void read_file(recordtype a[], int *n){
	FILE *f;
	f = fopen("data_2.txt", "r");
	int i = 0;
	if(f != NULL)
		while(!feof(f)){
			fscanf(f, "%d%f", &a[i].key, &a[i].other);
			i++;
		}
	else printf("ERORR");
	fclose(f);
	*n = i;
}

void print(recordtype a[], int n){
	int i;
	for(i=0; i<n; i++)
		printf("%3d%5d%8.2f\n", i+1, a[i].key, a[i].other);
}

int findPivot(recordtype a[], int i, int j){
	keytype firstkey;
	int k = i+1;
	firstkey = a[i].key;
	while(k<=j && a[k].key == firstkey)
		k++;
	if(k > j)
		return -1;
	if(a[k].key > firstkey)
		return k;
	return i;
}

int partition(recordtype a[], int i, int j, keytype pivot){
	int L = i;
	int R = j;
	while(L<=R){
		while(L<=R && a[L].key < pivot)
			L++;
		while(L<=R && a[R].key >= pivot)
			R--;
		if (L<R)
			swap(&a[L], &a[R]);
	}
	return L;
}

void quicksort(recordtype a[], int i, int j){
	keytype pivot;
	int index = findPivot(a, i, j);
	if(index != -1){
		pivot = a[index].key;
		k = partition(a, i, j, pivot);
		quicksort(a, i, k-1);
		quicksort(a, k, j);
	}
}



int main(){
	int n,i;
	recordtype a[MAX];
	printf("Selection Sort Algorithm\n\n");
	read_file(a, &n);
	printf("Before sorting:\n");
	print(a, n);
	quicksort(a, 0, n-1);
	printf("After sorting:\n");
	print(a, n);
	return 0;
}
