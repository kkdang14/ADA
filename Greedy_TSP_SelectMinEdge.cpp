#include <stdio.h>
#define MAX 100

typedef struct{
	float cost;
	int start, end;
}Edge;

void swap(Edge *x, Edge *y){
	Edge temp = *x;
	*x = *y;
	*y = temp;
}

void read_data(Edge a[], int *n){
	FILE *f;	
	int i,j,t;
	float temp;
	f = fopen("data.txt", "r");
	if(f=NULL){
		printf("ERORR\n");
		return;
	}
			
	fscanf(f, "%d", &n);
			int k = 0;
			for( int i=0; i<*n; i++)
				for(int j=i; j<*n; j++);
					if(i == j){
						for(int t=0; t<=j; t++);
							fscanf(f, "%f", &temp);
					}else{
						fscanf(f, "%f", &a[k].cost);
						a[k].start = i;
						a[k].end = j;
						k++;
					}
	fclose(f);
}

void print_list(Edge a[], int m, int la_PA){
	int i;
	float sum = 0.0;
	for(i=0; i<m; i++){
		printf("%3d %c%c = %8.2f\n", i+1, a[i].start+97, a[i].end+97, a[i].cost);
		if(la_PA == 0)
			sum += a[i].cost;
	}
	if(la_PA  == 1)
		printf("Tong do dai cac canh: %5.2f\n", sum);
}

int peak_3(Edge a[], int k, Edge newEdge){
	int i = 0;
	int cnt = 1;
	while(i<k && cnt < 3){
		if(newEdge.start == a[i].start || newEdge.end == a[i].end)
			cnt ++;
		i++;
	}
		
	if(cnt == 3) return 1;
	i = 0;
	cnt = 1;
	while(i<k && cnt < 3){
		if(newEdge.start == a[i].start || newEdge.end == a[i].end)
			cnt ++;
		i++;
	}
	
	return cnt == 3;
}

void init_forest(int parent[], int n){
	int i;
	for(i = 0; i<n; i++)
		parent[i] = i;
}

int find_Root(int parent[], int u){
	while(u != parent[u])
		u =parent[u];
	return u;
}

void update_forest(int parent[], int fr1, int fr2){
	parent[fr2] = fr1;
}

int has_circle(int start, int end){
	return (start == end);
}

void greedy(Edge listEdge[], int n, Edge a[]){
	int i,j,parent[n];
	init_forest(parent, n);
	int start, end;
	j=0;
	for(i=0; i<n*(n-1)/2 && j<n-1; i++){
		start = find_Root(parent, listEdge[i].start);
		end = find_Root(parent, listEdge[i].end);
		if((!peak_3(a, j, listEdge[i])) && !has_circle(start, end)){
			a[j] = listEdge[i];
			j++;
			update_forest(parent, start, end);
		}
	}
	
	for(; i<n*(n-1)/2; i++){
		start = find_Root(parent, listEdge[i].start);
		end = find_Root(parent, listEdge[i].end);
		if((!peak_3(a, n-1, listEdge[i])) && has_circle(start, end)){
			a[n-1] = listEdge[i];
			break;
		}
	}
}

void bb_sort(Edge a[], int n) {
	int i,j;
	for(i=0; i<=n-2; i++)
		for(j=n-1; j>=i+1; j--)
			if(a[j].cost > a[j-1].cost)
				swap(&a[j], &a[j-1]);
     
}

int main(){
	Edge list_edge[MAX];
	int n;
	printf("Greedy_TSP\n");
	read_data(list_edge, &n);
	printf("List of graph: \n");
	print_list(list_edge, n*(n-1)/2, 0);
	bb_sort(list_edge, n*(n-1)/2);
	printf("After sort: \n");
	print_list(list_edge, n*(n-1)/2, 0);
	Edge a[n];
	greedy(list_edge, n, a);
	printf("PHUONG AN\n");
	print_list(list_edge, n, 1);
	
	
	return 0;
}
