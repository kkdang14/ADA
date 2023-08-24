#include <stdio.h>
#define MAX 100

typedef int keytype;
typedef float othertype;

typedef struct{
    keytype key;
    othertype other;
} record;

void swap(record *x, record *y){
    record temp = *x;
    *x = *y;
    *y = temp;
}

void read_data(record a[], int *n){
    FILE *f;
    f = fopen("data_2.txt", "r");
    int i = 0;
    if(f != NULL)
        while(!feof(f)){
            fscanf(f, "%d%f", &a[i].key, &a[i].other);
            i++;
        }
    else printf("ERROR\n");
    fclose(f);
    *n = i;
}

void print_data(record a[], int n){
    int i;
    printf("%3s%5s%8s\n", "No", "Key", "Other");
    for(i=0; i<n; i++){
        printf("%3d%5d%8.2f\n", i+1, a[i].key, a[i].other);
    }
}

void pushDown(record a[], int first, int last){
    int r = first;
    while (r <= (last-1)/2) {
        int left = 2*r + 1;
        int right = 2*r + 2;
        int largerChild;
        if (right <= last && a[right].key > a[left].key)
            largerChild = right;
        else
            largerChild = left;
        if (a[r].key >= a[largerChild].key)
            return;
        swap(&a[r], &a[largerChild]);
        r = largerChild;
    }
}

void heap_sort(record a[], int n){
    int i;
    for (i = (n-2)/2; i >= 0; i--)
        pushDown(a, i, n-1);
    for (i = n-1; i >= 2; i--) {
        swap(&a[0], &a[i]);
        pushDown(a, 0, i-1);
    }
    
    swap(&a[0], &a[1]);
}


int main(){
    int n;
    record a[MAX];
    printf("Heap Sort Algorithm\n\n"); // change Selection Sort to Heap Sort
    read_data(a, &n);
    printf("Before sorting:\n");
    print_data(a, n);
    heap_sort(a, n);
    printf("After sorting:\n");
    print_data(a, n);
    return 0;
}



