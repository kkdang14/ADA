#include <stdio.h>

#define MAX_LENGTH 80


typedef struct {
	int key;
	int value;
	float price;
	int result;
	char name[MAX_LENGTH];
} Item;


void input_file (Item items[], int *n, int *w) {

	freopen ("BB_TSP.txt", "r", stdin);
	scanf("%d", w);
	int i = 0;
	while (!feof(stdin)) {
		scanf("%d%d%[^\n]", &items[i].key, &items[i].value, &items[i].name);
		items[i].price = 1.0*items[i].value / items[i].key;
		i += 1;
	}

	*n = i;
}


void output_file (Item items[], int n, int sum) {
	for (int i = 0; i < n; ++i) {
		printf("%d.\n[ key: %d, value: %d name:%s ]: [%d]\n", i, items[i].key, items[i].value, items[i].name, items[i].result);
		sum += items[i].result;
	}
	printf("%d\n", sum);
}

void swap (Item *x, Item *y) {
	Item temp = *x;
	*x = *y;
	*y = temp;
}

void bb_sort (Item items[], int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = n - 1; j > i; --j) {
			if (items[j].price > items[j - 1].price) {
				swap(&items[j], &items[j - 1]);
			}
		}
	}
}

// void root (float price_max, int *w, int *t, float *ct) {
// 	*t = 0;
// 	*ct = *w * price_max;
// }

// void branch_bound (Item items[], int result[], int n, int w, int *t, float *ct, float *max_temp, int k) {
// 	int num_items = w / items[k].key;

// 	for (int i = num_items; i >= 0; --i)  {
// 		*t = *t + i * items[k].value;
// 		w = w - i * items[k].key;
// 		result[k] = i;

// 		if (k < n - 1) {
// 			*ct = *t + w * items[k + 1].price;
// 		}

// 		if (k == n - 1 || w == 0) {
// 			if (*t > *max_temp) {
// 				*max_temp = *t;
// 				for (int i = 0; i < n; ++i) {
// 					items[i].result = result[i];
// 				}
// 			}
// 		}

// 		else if (*ct > *max_temp) {
// 			branch_bound(items, result, n, w, t, ct, max_temp, k + 1);
// 		}

// 		*t = *t - i * items[k].value;
// 		w = w + i * items[k].key;
// 		result[k] = 0;
// 	}

// }

void root (int price_max, float *ct, int w, int *t) {
	*t = 0;
	*ct = *t + w * price_max; 

}

void branch_bound (Item items[], int result[], int n, float *max_temp, float *ct, int *w, int *t, int k) {
	int m = *w / items[k].key;

	for (int i = 0; i < m; ++i) {

		*w = *w - i * items[k].key;
		*t = *t + i * items[k].value;

		result[k] = i;

		if (k < n - 1) {
			*ct = *t + *w * items[k + 1].price;
		}

		if (k == n - 1 || w == 0) {
			if (*ct > *max_temp) {
				*max_temp = *ct;

				for (int j = 0; j < n; ++j) {
					items[j].result = result[j];
				}
			}
		}
		else if (*ct > *max_temp) {
			branch_bound(items, result, n, max_temp, ct, w, t, k + 1);
		}

		*w = *w + i * items[k].key;
		*t = *t - i * items[k].value;

		result[k] = 0;
	}

}


int main () {
	int n, w, sum = 0;
	int t, k = 0;
	float ct, max_temp = 0;
	int result[MAX_LENGTH];

	for (int i = 0; i < n; ++i) {
		result[i] = 0;
	}

	Item items[MAX_LENGTH];

	input_file(items, &n, &w);
	bb_sort(items, n);
	output_file(items, n, sum);

	root(items[0].price, &ct, w, &t);

	branch_bound(items, result, n, &max_temp, &ct, &w, &t, k);

	output_file(items, n, sum);

	return 0;
}

