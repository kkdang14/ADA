int findPivot(record a[], int i, int j){
	keytype firstkey;
	int k = i + 1;
	firstkey = a[i].key;
	while (k<=j && a[k].key == firstkey)
		k++;
	if(k>j)	
		return -1;
	if(a[i].key > firstkey)
		return k;
	return i;
}

int partition(record a[], int i, int j, keytype pivot){
	int L=i;
	int R=j;
	while(L<=R){
		while(L<=R && a[L].key < pivot)
			L++;
		while(L<=R && a[R].key >= pivot)
			R--;
		if(L < R)
			swap(&a[L], &a[R]);
	}
	return L;
}

void quicksort(record a[], int i, int j){
	keytype pivot;
	int index;
	int k;
	index = findPivot(a, i, j);
	if(index != -1){
		pivot = a[index].key;
		k = partition(a, i, j, pivot);
		quicksort(a, i, k-1);
		quicksort(a, k, j);
	}
}











void pushDown(record a[], int first, int last){
	int r =first;
	while(r <= (last-1)/2){
		if(last == 2*r+1){
			if(a[r].key < a[last].key)
				swap(&a[r], &a[last]);
			r= last;
		}else{
			if(a[r].key < a[2*r+1].key && a[2*r+1].key >= a[2*r+2].key){
				swap(&a[r], &a[2*r+1]);
				r = 2*r+1;
			}else if(a[r].key < a[2*r+2].key){
				swap(&a[r], &a[2*r+2]);
				r = 2*r+2;
			}else{
				r = last;
			}
		}
	}
}


void heap_sort(record a[], int n){
	int i;
	for(i=(n-2)/2; i>=0; i--)
		pushDown(a, 0, n-1);
	for(i=n-1; i>=2; i--){
		swap(&a[0], &a[i]);
		pushDown(a, 0, i-1);
	}
	
	swap(&a[0], &a[1]);
	
}




int i, j;
for(i=1, i<=n-1; i++)?
i=j
while(i>0 && a[i].key < a[j-1].key)
	swap
	j--;
	
	
bbsort


for(i=0; i<=n-2; i++)
	for(j=n-1; j>=i+1; j--)
		if(a[j] < a[j-1])
			swap
