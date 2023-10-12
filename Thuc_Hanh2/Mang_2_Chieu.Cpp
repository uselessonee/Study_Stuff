#include <stdio.h>
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

void demTongSoNguyenTo(int **matrix)
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

    // while
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

int Horse_cock()
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

void sum_matrices(int **A, int **B, int **C)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

int main()
{
    printf("Nhap so dong va cot: ");
    scanf("%d", &m);
    scanf("%d", &n);
    Init_Matrix(&matrix);
    Print_Matrix(matrix, m, n);

    // Find max, min
    printf("Gia tri lon nhat la: %d \n", find_Max(matrix));
    printf("Gia tri nho nhat la: %d \n", find_Min(matrix));

    // find POS
    printf("Nhap gia tri can tim vi tri: ");
    scanf("%d", &x);
    Print_Pos();

    printf("%d", Horse_cock());

    sort_matrix();

    printf("Tong duong cheo chinh: %d", sum_diagonal_elements());
}
