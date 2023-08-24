//Brand and Bound: Backpack Problem 1

#include <stdio.h>
#include <malloc.h>
#include <String.h>
#define MAXN 100

typedef struct{
	float value, weight, price;
	char name[MAXN];
	int way, amount;
}Item;

Item *readfromfile(float *W, int *n){
	FILE *f;
	f = fopen("CaiBalo2.txt", "r");
	fscanf(f, "%f", W);
	Item *listItem;
	listItem = (Item*)malloc(sizeof(Item));
	int i = 0;
	while(!feof(f)){
		fscanf(f, "%f%f%d%[^\n]", &listItem[i].weight, &listItem[i].value, &listItem[i].amount, &listItem[i].name);
		listItem[i].price = listItem[i].value / listItem[i].weight;
		listItem[i].way = 0;
		i++;
		listItem = (Item*)realloc(listItem, sizeof(Item)*(i+1));
	}
	
	*n = i;
	fclose(f);
	return listItem;
}

void swap(Item *x, Item *y){
	Item temp = *x;
	*x = *y;
	*y = temp;
}

void bb_sort(Item *a, int n){
	int i, j;
	for(i=0; i<=n-2; i++)
		for(j= n-1; j>=i+1; j--){
			if(a[j].price < a[j-1].price)
				swap(&a[j], &a[j-1]);
		}
}

void print_listItem(Item *listItem, int n, float W){
	printf("BRAND AND BOUND ALGORITHM FOR BACKPACK PROBLEM\n");
	int i;
	float TongTL = 0.0, TongGT = 0.0;
	printf("Phuong an toi uu: ");
	for(i=0; i<n-1; i++){
		printf("%d ", listItem[i].way);
		TongTL += listItem[i].way * listItem[i].weight;
		TongGT += listItem[i].way * listItem[i].value;
	}
	
	printf("\nTrong luong co the chua cua balo: %.2f\n", W);
	printf("Tong trong luong: %.2f\n", TongTL);
	printf("Tong gia tri: %.2f\n", TongGT);
		
		
}

void create_root(float W, float *V, float *CT, float *GTLNTT, float *TGT, float DG_Max){
	*TGT = 0.0;
	*V = W;
	*CT = *V * DG_Max;
	*GTLNTT = 0.0;
}

void update_MaxValue(float TGT, float *GTLNTT, int x[], Item *listItem, int n){
	int i;
	if(*GTLNTT < TGT){
		*GTLNTT = TGT;
		for(i=0; i<n; i++)
			listItem[i].way = x[i];
	}
}

int min(int a, int b){
	return a<b? a:b;
}

void Brand_Bound(int i, float *TGT, float *CT, float *V, float *GTLNTT, int x[], Item *listItem, int n){
	int j;
	int k =min(listItem[i].amount, *V / listItem[i].weight);
	for(j= k; j>=0; j--){
		*TGT = *TGT + j*listItem[i].value;
		*V = *V - j*listItem[i].weight;
		*CT = *TGT + *V * listItem[i+1].price;
		
		if(*CT > *GTLNTT){
			x[i]= j;
			if((i == n-1) || (*V == 0.0))
				update_MaxValue(*TGT, GTLNTT, x, listItem, n);
			else
				Brand_Bound(i+1, TGT, CT, V, GTLNTT, x, listItem, n);
		}
		
		x[i] = 0;
		*TGT = *TGT - j*listItem[i].value;
		*V = *V + j*listItem[i].weight;
	}
}

int main(){
	Item *listItem;
	int n;
	float W;
	float CT, TGT, V, GTLNTT;
	listItem = readfromfile(&W, &n);
	int x[n];
	bb_sort(listItem, n);
	create_root(W, &V, &CT, &GTLNTT, &TGT, listItem[0].price);
	Brand_Bound(0, &TGT, &CT, &V, &GTLNTT, x, listItem, n);
	print_listItem(listItem, n, W);
	
	free(listItem);
	return 0;
}
