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

void insertion_sort(recordtype a[], int n) {
    int i,j;
    for (i = 1; i <= n-1; i++){
    	j=i;
    	while(j>0 && a[j].key < a[j-1].key){
    		swap(&a[j], &a[j-1]);
    		j--;
		}
	}
     
}

int main(){
	int n,i;
	recordtype a[MAX];
	printf("Selection Sort Algorithm\n\n");
	read_data(a, &n);
	printf("Before sorting:\n");
	print_data(a, n);
	insertion_sort(a, n);
	printf("After sorting:\n");
	print_data(a, n);
	return 0;
}
