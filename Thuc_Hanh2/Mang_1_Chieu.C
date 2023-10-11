#include <stdio.h>
#include <conio.h>
 int* arr;
 int n;


void Nhap_Mang()
{
    printf("Nhap N:");
    scanf("%d", &n);

    arr = (int*)malloc(n * sizeof(int));
    for (int i =0; i<= sizeof(arr)/ sizeof(int); i++)
    {
        printf("Nhap phan tu thu %d", i);
        scanf("%d", &arr[i]);
    } 
}


void Xuat_Mang()
{
    for (int i =0; i<= n; i++)
    {
        printf("Phan tu thu i la %d \n", arr[i]);
    }
}

int find_Max()
{
    int max=0;
    for (int i =0; i<= n; i++)
    {
        max = (arr[i] > max) ? arr[i] : max;
    }
    return max;
}
int main()
{
    Nhap_Mang();
    Xuat_Mang();

    free(arr);
}