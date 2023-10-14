#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int n, m;
int x;
int **matrix;

// Init Matrix
void Init_Matrix(int ***matrix)
{
    *matrix = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
    {
        (*matrix)[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
        {
            printf("Nhap phan tu thu [%d][%d]: ", i, j);
            scanf("%d", &(*matrix)[i][j]);
        }
    }
}

// print out the matrix
void Print_Matrix(int **matrice, int rows, int cols)
{
    printf("In ma tran:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }
}

int find_Max(int **matrix)
{
    int max = matrix[0][0];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] > max)
            {
                max = matrix[i][j];
            }
        }
    }
    return max;
}

int find_Min(int **matrix)
{
    int min = matrix[0][0];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] < min)
            {
                min = matrix[i][j];
            }
        }
    }
    return min;
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

// The name said everything
void Count_Prime_Sum_Num()
{
    int count = 0;
    int sum;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (isPrime(matrix[i][j]))
            {
                count++;
            }
            sum += matrix[i][j];
        }
    }

    printf("So phan tu nguyen to : %d \n", count);
    printf("Tong cac phan tu trong matrix: %d \n", sum);
}

// Find X
void Print_Pos()
{
    int found = 0;
    printf("Vi tri cac phan tu co gia tri bang %d la: ", x);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == x)
            {
                printf("%d %d \n", i, j);
                found = 1;
            }
        }
    }
    if (!found)
    {
        printf("Khong co phan tu nao co gia tri bang %d", x);
    }
    printf("\n");
}

int Find_Max(int *arr, int n)
{
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
int Saddle_Point()
{
    int i, j;
    int count = 0;
    int col;
    float max;
    float min;

    for (i = 0; i < m; i++)
    {
        max = matrix[i][0];
        col = 0;
        for (j = 1; j < m; j++)
        {
            // Find max in a row
            if (max < matrix[i][j])
            {
                max = matrix[i][j];
                col = j;
            }
        }

        // Find min in a column
        min = matrix[0][col];
        for (int i = 1; i < n; i++)
        {
            if (min > matrix[i][col])
            {
                min = matrix[i][col];
            }
        }

        // Compare maximum in row and minimm in column
        if (max == min)
        {
            count++;
        }
    }

    return count;
}

// Sorting
void sort_matrix()
{
    int **matrice_sorted;
    matrice_sorted = matrix;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (matrice_sorted[i][j] > matrice_sorted[i][j + 1])
            {
                int temp = matrice_sorted[i][j];
                matrice_sorted[i][j] = matrix[i][j + 1];
                matrice_sorted[i][j + 1] = temp;
            }
        }
    }
    printf("Ma tran sau khi sap xep:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrice_sorted[i][j]);
        }
        printf("\n");
    }
}

// Straight to HELL BABY!
int sum_diagonal_elements()
{
    int size = m > n ? m : n;
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum += matrix[i][i];
    }

    return sum;
}

// I have no talent when it comes to naming things...

int count_even_elements_in_upper_triangle()
{
    int size = m > n ? m : n;

    int count = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (matrix[i][j] % 2 == 0)
            {
                count++;
            }
        }
    }

    return count;
}

void Print_Odd_Nums_On_SecDiagonal()
{
    int i = 0;
    int size = m > n ? m : n;
    int j = size - 1;

    printf("Cac so le trong tam giac duoi duong cheo phu:");
    while (i < size && j >= 0)
    {
        printf("%d ", matrix[i][j]);

        if (matrix[i][j] % 2 != 0)
        {
            printf("*");
        }

        i++;
        j--;
    }
}

// Sum...
void sum_matrices()
{
    int **A;
    int **B;
    int **C;

    printf("Nhap dong va cot:");
    scanf("%d", &m);
    scanf("%d", &n);

    printf("Tao ma tran A:");
    Init_Matrix(&A);

    printf("Tao ma tran B:");
    Init_Matrix(&B);
    C = A;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    Print_Matrix(C, m, n);
}
int main()
{
    // 1
    printf("Nhap so dong va cot: ");
    scanf("%d", &m);
    scanf("%d", &n);
    // 2
    Init_Matrix(&matrix);
    // 3
    printf("\n Enter de tiep tuc");
    getch();
    system("cls");
    Print_Matrix(matrix, m, n);

    // 4
    printf("Gia tri lon nhat la: %d \n", find_Max(matrix));
    printf("Gia tri nho nhat la: %d \n", find_Min(matrix));
    printf("\n Enter de tiep tuc");
    getch();
    system("cls");

    // 5
    printf("\n Enter de tiep tuc");
    getch();
    system("cls");
    Count_Prime_Sum_Num();

    // 6
    printf("\n Enter de tiep tuc");
    getch();
    system("cls");
    printf("Nhap gia tri can tim vi tri: ");
    scanf("%d", &x);
    Print_Pos();

    // 7
    printf("\n Enter de tiep tuc");
    getch();
    system("cls");
    printf("\n diem yen ngua: %d", Saddle_Point());

    // 8
    printf("\n Enter de tiep tuc");
    getch();
    system("cls");
    sort_matrix();

    // 9
    printf("\n Enter de tiep tuc");
    getch();
    system("cls");
    printf("Tong duong cheo chinh: %d", sum_diagonal_elements());

    // 10
    printf("\n Enter de tiep tuc");
    getch();
    system("cls");
    printf("\n So chang nam trong tam giac tren:", count_even_elements_in_upper_triangle());

    // 11
    printf("\n Enter de tiep tuc");
    getch();
    system("cls");
    Print_Odd_Nums_On_SecDiagonal();

    printf("\n Enter de tiep tuc");
    getch();
    system("cls");

    // 12
    sum_matrices();

    getch();
}
