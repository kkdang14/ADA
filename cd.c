#include <stdio.h>
#include <string.h>

typedef struct
{
    float x, y;
    int c;
} Point;

float minx(Point d[], int n)
{
    int i;
    float min = d[0].x;
    for (i = 0; i < n; i++)
    {
        if (d[i].x < min)
        {
            min = d[i].x;
        }
    }
    return min;
}
void sortx(Point d[], int n)
{
    int i, j;
    float temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (d[i].x > d[j].x)
            {

                temp = d[i].x;
                d[i].x = d[j].x;
                d[j].x = temp;

                temp = d[i].y;
                d[i].y = d[j].y;
                d[j].y = temp;

                temp = d[i].c;
                d[i].c = d[j].c;
                d[j].c = temp;
            }
        }
    }
}
int count(int tc, Point d[], int n)
{
    int i, count = 0;
    for (i = 0; i < n; i++)
    {
        if (d[i].c >= tc)
            count++;
    }
    return count;
}

int main()
{
    Point My[3];
    int i;
    int tc;
    printf("Nhap tc: ");
    scanf("%d", &tc);

    for (i = 0; i < 3; i++)
    {
        printf("Nhap point %d:\n ", i + 1);
        scanf("%f%f%d", &My[i].x, &My[i].y, &My[i].c);
    }

    sortx(My, 3);
    printf("Diem anh co hoanh do nho nhat la: ");
    printf("%.2f\n", minx(My, 3));
    printf("Cac diem anh sau khi sap xep:\n");
    for (i = 0; i < 3; i++)
    {
        printf("%.2f %.2f %d\n ", My[i].x, My[i].y, My[i].c);
    }
    printf("Cac diem anh co ma mau lon hon %d: ", tc);
    printf("%d\n", count(tc, My, 3));
    return 0;
}
