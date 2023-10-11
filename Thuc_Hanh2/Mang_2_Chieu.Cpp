#include <stdio.h>
#include <stdlib.h>
int n,m;
int x;
void Init_Matrix(int*** matrix) {
    *matrix = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        (*matrix)[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            printf("Nhap phan tu thu [%d][%d]: ", i, j);
            scanf("%d", &(*matrix)[i][j]);
        }
    }
}


void Print_Matrix(int** matrix) {
    printf("Ma tran vua nhap:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int find_Max(int** matrix) {
    int max = matrix[0][0];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }
    }
    return max;
}

int find_Min(int** matrix) {
    int min = matrix[0][0];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] < min) {
                min = matrix[i][j];
            }
        }
    }
    return min;
}

int isPrime(int num) {
    if (num < 2) {
        return 0;
    }
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}


void demTongSoNguyenTo(int** matrix) {
    int count =0;
    int sum;
     for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (isPrime(matrix[i][j])) {
                count++;
            }
            sum += matrix[i][j];
        }
    }

    printf("So phan tu nguyen to : %d \n", count);
    printf("Tong cac phan tu trong matrix: %d \n", sum);
}


void Print_Pos(int** matrix) {
    int found = 0;
    printf("Vi tri cac phan tu co gia tri bang %d la: ", x);
    for (int i = 0; i < m; i++) {
        for(int j=0; j< n; j++)
        {
            if (matrix[i][j] == x) 
            {
            printf("%d %d \n", i,j);
            found = 1;
            }
        }
    }

    // while
    if (!found) {
        printf("Khong co phan tu nao co gia tri bang %d", x);
    }
    printf("\n");
}


int Find_Max(int* arr, int n) {
    int max = arr[0];
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int Horse_cock(int** matrix)
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
        for (j = 1; j < n; j++)
        {
            // Find maximum in a row
            if (max < matrix[i][j])
            {
                max = matrix[i][j];
                col = j;
            }
        }
 
        // Find minimum in a column col
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

void sort_matrix(int **matrix, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols - 1; j++) {
      if (matrix[i][j] > matrix[i][j + 1]) {
        int temp = matrix[i][j];
        matrix[i][j] = matrix[i][j + 1];
        matrix[i][j + 1] = temp;
      }
    }
  }
}

int main()
{
    int** matrix;
    printf("Nhap so dong va cot: ");
    scanf("%d", &m);
    scanf("%d", &n);
    Init_Matrix(&matrix);
    Print_Matrix(matrix);
    
    printf("Gia tri lon nhat la: %d \n", find_Max(matrix));
    printf("Gia tri nho nhat la: %d \n", find_Min(matrix));

    printf("Nhap gia tri can tim vi tri: ");
    scanf("%d", &x);
    Print_Pos(matrix);
    
    printf("%d",Horse_cock(matrix));

    sort_matrix(matrix, rows, cols);

    printf("Ma tran sau khi sap xep:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
        printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}