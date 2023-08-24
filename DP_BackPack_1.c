#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[20];
    int weight, value, solve;
} Item;

typedef int table[50][100];

Item *read_file(int *W, int *n)
{
    FILE *f;
    f = fopen("DPBP1.txt", "r");
    fscanf(f, "%d", W);
    Item *list_item;
    list_item = (Item *)malloc(sizeof(Item));
    int i = 0;
    while (!feof(f))
    {
        fscanf(f, "%d%d%[^\n]", &list_item[i].weight, &list_item[i].value, &list_item[i].name);
        list_item[i].solve = 0;
        i++;
        list_item = (Item *)realloc(list_item, sizeof(Item) * (i + 1));
    }
    *n = i;
    fclose(f);
    return list_item;
}

void print_solve(Item *list_item, int n, int W)
{
    int i, tongTL = 0, tongGT = 0;
    printf("Phuong an: \n");
    printf("|---|------------------|--------|---------|-----------|\n");
    printf("|STT|    Ten do vat    |   TL   |    GT   |     PA    |\n");
    printf("|---|------------------|--------|---------|-----------|\n");
    for (i = 0; i < n; i++)
    {
        printf("|%2d |%-18s|%5d   |%5d    |%6d     |\n", i+1, list_item[i].name, list_item[i].weight, list_item[i].value, list_item[i].solve);
        tongTL = tongTL + list_item[i].solve * list_item[i].weight;
        tongGT = tongGT + list_item[i].solve * list_item[i].value;
    }
    printf("|---|------------------|--------|---------|-----------|\n");
    printf("\nTrong luong cua balo: %d", W);
    printf("\nTong Trong Luong: %d", tongTL);
    printf("\nTong Gia Tri: %d", tongGT);
}

void init_table(Item *list_item, int n, int W, table F, table X)
{
    int xk, yk, k;
    int Xmax, Fmax;
    int V;
    for (V = 0; V <= W; V++)
    {
        X[0][V] = V / list_item[0].weight;
        F[0][V] = X[0][V] * list_item[0].value;
    }

    for (k = 1; k <= n; k++)
        for (V = 0; V <= W; V++)
        {
            Fmax = F[k - 1][V];
            Xmax = 0;
            yk = V / list_item[k].weight;
            for (xk = 0; xk < yk; xk++)
                if (F[k -1][V - xk * list_item[k].weight] + xk * list_item[k].value > Fmax)
                {
                    Fmax = F[k-1][V - xk * list_item[k].weight] + xk * list_item[k].value;
                    Xmax = xk;
                }
            F[k][V] = Fmax;
            X[k][V] = Xmax;
        }
}

void print_table(int n, int W, table F, table X)
{
    int V, k;
    for (k = 0; k < n; k++)
    {
        for (V = 0; V <= W; V++)
            printf("|%4d%2d", F[k][V], X[k][V]);
        printf("\n");
    }
}

void test_table(Item *list_item, int n, int W, table X)
{
    int V, k;
    V = W;
    for (k = n-1; k >= 0; k--)
    {
        list_item[k].solve = X[k][V];
        V = V - X[k][V] * list_item[k].weight;
    }
}

int main()
{
    int n, W;
    table X, F;
    Item *list;
    list = read_file(&W, &n);
    init_table(list, n, W, F, X);
    print_table(n, W, F, X);
    printf("\n");
    test_table(list, n, W, X);
    print_solve(list, n, W);
    free(list);
    return 0;
}
