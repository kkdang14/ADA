#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct{
	char name[20];
	float weight, value, price, amount;
	int solve;
}Item;

Item *readFile(float *W, int *n){
	FILE *f;
	f = fopen("CaiBalo2.txt", "r");
	fscanf(f,"%f", W);
	Item *list;
	list = (Item*)malloc(sizeof(Item));
	int i = 0;
	while(!feof(f)){
		fscanf(f, "%f%f%f%[^\n]", &list[i].weight, &list[i].value, &list[i].amount, &list[i].name);
		list[i].price = list[i].value / list[i].weight;
		list[i].solve = 0;
		i++; 
		list = (Item*)realloc(list, sizeof(Item)*(i+1));
	}
	*n= i;
	fclose(f);
	return list;
}

void swap(Item *x, Item *y){
	Item temp = *x;
	*x = *y;
	*y = temp;
}

void bbsort(Item *list, int n){
	int i,j;
	for(i=0; i<=n-2; i++)
		for(j=n-1; j>=i+1; j--)
			if(list[j].price > list[j-1].price)
				swap(&list[j], &list[j-1]);
}

void printList(Item *list, int n, int W){
	int i;
	float TongTL= 0.0, TongGT = 0.0;
	printf("PHUONG AN:\n");
	printf("|---|------------------|---------|---------|---------|---------|-----------|\n");
	printf("|STT|     Ten Do Vat   | T Luong | Gia Tri | Don Gia |  SLuong | Phuong an |\n");
	printf("|---|------------------|---------|---------|---------|---------|-----------|\n");
	for(i=1; i<n; i++){
		printf("|%2d |%-18s|%9.2f|%9.2f|%9.2f|%9.2f|%6d	   |\n", i, list[i].name, list[i].weight, list[i].value, list[i].price, list[i].amount, list[i].solve);
		TongTL += list[i].solve * list[i].weight;
		TongGT += list[i].solve * list[i].value;	
	}
	
	printf("|---|------------------|---------|---------|---------|---------|-----------|\n");
	printf("\nTong trong luong: %.2f", TongTL);
	printf("\nTong gia tri: %.2f", TongGT);
		
}

int min(int a, int b){
	return a<b ? a:b;
}


void Greedy(Item *list, int n, float W){
	int i;
	for(i=0; i<n; i++){
		list[i].solve = min(W/list[i].weight, list[i].amount);
		W = W- list[i].solve*list[i].weight;
	}
}


int main(){
	int n;
	float W;
	Item *list;
	list = readFile(&W, &n);
	bbsort(list, n);
	Greedy(list, n, W);
	printList(list, n, W);
	free(list);
	return 0;
}
