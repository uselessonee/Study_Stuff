#include <stdio.h>
#include <stdlib.h>

void Init_Matrix(int*** matrix, int m, int n) {
    *matrix = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        (*matrix)[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            printf("Nhap phan tu thu [%d][%d]: ", i, j);
            scanf("%d", &(*matrix)[i][j]);
        }
    }
}


void Print_Matrix(int** matrix, int m, int n) {
    printf("Ma tran vua nhap:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int find_Max(int** matrix, int m, int n) {
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

int find_Min(int** matrix, int m, int n) {
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


int laSoNguyenTo(int num) {
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

int main()
{
    int** matrix;
    int n,m;
    printf("Nhap so dong va cot: ");
    scanf("%d", &m);
    scanf("%d", &n);
    Init_Matrix(&matrix, m,n);
    Print_Matrix(matrix, m,n);
    
    printf("Gia tri lon nhat la: %d \n", find_Max(matrix, n,m));
    printf("Gia tri nho nhat la: %d \n", find_Min(matrix, n,m));
}