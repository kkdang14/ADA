#include <stdio.h>
#include <string.h>
#define MAX 100

//typedef int keytype;
//typedef float othertype;
//
//typedef struct{
//	keytype key;
//	othertype other;
//}recordtype;

typedef struct{
	char moneytype[MAX];
	int value, way;
}Money;

void swap(Money *x, Money *y){
	Money temp = *x;
	*x = *y;
	*y = temp;
}

void read_data(Money a[], int *n){
	FILE *f;
	f = fopen("ATM.txt", "r");
	int i=0;
	if(f!=NULL)
		while(!feof(f)){
			fscanf(f,"%d%[^\n]", &a[i].value, a[i].moneytype);
			a[i++].way = 0;
		}
	else printf("ERORR\n");	
	*n=i;
	fclose(f);
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

void print_data(Money a[], int n){
	int i;
	for(i=0; i<n; i++){
		if(a[i].way > 0)
			printf("%d to %d VND %s\n", a[i].way, a[i].value, a[i].moneytype);
	}
	
}

void bubble_sort(Money a[], int n) {
	int i,j;
	for(i=0; i<=n-2; i++)
		for(j=n-1; j>=i+1; j--)
			if(a[j].value > a[j-1].value)
				swap(&a[j], &a[j-1]);
     
}

void greedy(Money a[], int n, int needpay){
	int i=0;
	int s_way = 0;
	bubble_sort(a, n);
	while(i<n && needpay >0){
		a[i].way = needpay/a[i].value;
		s_way+=a[i].way;
		needpay = needpay - a[i].way * a[i].value;
		i++;
	}
	
	printf("So to tien can tra: %d to\n", s_way);
}


int main(){
	int n,i;
	int needpay;
	scanf("%d", &needpay);
	Money a[MAX];
	read_data(a, &n);
	greedy(a, n, needpay);
	print_data(a, n);
	return 0;
}
