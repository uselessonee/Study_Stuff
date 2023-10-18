#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int n;
void Init_Arr(int **arr)
{
    *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &(*arr)[i]);
    }
}

void Print_Arr(int *arr)
{
    printf("Mang vua nhap la: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int Find_Max(int *arr)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

int tinhTich(int *arr)
{
    int tich = 1;
    for (int i = 0; i < n; i++)
    {
        tich *= arr[i];
    }
    return tich;
}

int isPrime(int num)
{
    if (num < 2)
    {
        return 0;
    }
    for (int i = 2; i <= num / 2; i++)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

void demTongSoNguyenTo(int *arr)
{
    int count, sum;
    count = 0;
    sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (isPrime(arr[i]))
        {
            (count)++;
            (sum) += arr[i];
        }
    }
    printf("So phan tu nguyen to trong mang la: %d\n", count);
    printf("Tong cac phan tu nguyen to trong mang la: %d\n", sum);
}

void Print_Pos(int *arr, int x)
{
    int found = 0;
    printf("Vi tri cac phan tu co gia tri bang %d la: ", x);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            printf("%d ", i);
            found = 1;
        }
    }
    if (!found)
    {
        printf("Khong co phan tu nao co gia tri bang %d", x);
    }
    printf("\n");
}

void Sorting(int *arr)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void Add_Vaule(int *arr, int x, int Pos)
{
    n++;
    arr = (int *)realloc(arr, n * sizeof(int));
    for (int i = n - 1; i > Pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[Pos] = x;
}


void Del_Vaule(int *arr, int k)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == k)
        {
            count++;
        }
        else
        {
            arr[i - count] = arr[i];
        }
    }
    n -= count;
    arr = (int *)realloc(arr, n * sizeof(int));
}

int main()
{
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);

    int *arr;

    Init_Arr(&arr);
    Print_Arr(arr);
    printf("\n Enter de tiep tuc");
    getch();
    system("cls");

    printf("Gia tri lon nhat trong mang la: %d\n", Find_Max(arr));
    printf("\n Enter de tiep tuc");
    getch();
    system("cls");

    printf("Tich cac phan tu trong mang la: %d\n", tinhTich(arr));
    printf("\n Enter de tiep tuc");
    getch();
    system("cls");

    demTongSoNguyenTo(arr);
    printf("\n Enter de tiep tuc");
    getch();
    system("cls");

    int x;
    printf("Nhap gia tri can tim vi tri: ");
    scanf("%d", &x);
    Print_Pos(arr, x);
    printf("\n Enter de tiep tuc");
    getch();
    system("cls");

    Sorting(arr);
    printf("Mang sau khi sap xep tang dan: ");
    Print_Arr(arr);
    printf("\n Enter de tiep tuc");
    getch();
    system("cls");

    int Pos, giaTri;
    printf("Nhap gia tri can chen: ");
    scanf("%d", &giaTri);
    printf("Nhap vi tri can chen: ");
    scanf("%d", &Pos);
    Add_Vaule(&arr, giaTri, Pos);
    printf("Mang sau khi chen gia tri: ");
    Print_Arr(arr);
    printf("\n Enter de tiep tuc");
    getch();
    system("cls");

    int k;
    printf("Nhap gia tri can xoa: ");
    scanf("%d", &k);
    Del_Vaule(arr, k);
    printf("Mang sau khi xoa gia tri: ");
    Print_Arr(arr);
    printf("\n Enter de ket thuc");
    getch();
    system("cls");

    free(arr);

    return 0;
}
