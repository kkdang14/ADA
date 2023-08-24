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


//void read_data(recordtype a[], int *n){
//	FILE *f;
//	f = freopen("data_2.txt", "r", stdin);
//	int i=0;
//	if(f!=NULL)
//		while(!feof(f)){
//			scanf("%d%f", &a[i].key, &a[i].other);
//			i++;
//		}
//	else printf("ERORR\n");	
//	*n=i;
//}

void print_data(recordtype a[], int n){
	int i;
	for(i=0; i<n; i++)
		printf("%3d%5d%8.2f\n", i+1, a[i].key, a[i].other);
	
}

void bubble_sort(recordtype a[], int n) {
	int i,j;
	for(i=0; i<=n-2; i++)
		for(j=n-1; j>=i+1; j--)
			if(a[j].key < a[j-1].key)
				swap(&a[j], &a[j-1]);
     
}


int main(){
	int n,i;
	recordtype a[MAX];
	printf("Selection Sort Algorithm\n\n");
	read_data(a, &n);
	printf("Before sorting:\n");
	print_data(a, n);
	bubble_sort(a, n);
	printf("After sorting:\n");
	print_data(a, n);
	return 0;
}
