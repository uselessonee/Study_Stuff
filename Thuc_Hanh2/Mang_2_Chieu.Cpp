#include <stdio.h>
#include <stdlib.h>
int n,m;
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


void Print_Pos(int** matrix, int x) {
    int found = 0;
    printf("Vi tri cac phan tu co gia tri bang %d la: ", x);
    for (int i = 0; i < n; i++) {
        for(int j=0; j<= m; j++)
        {
            if (arr[i][j] == x) {
            printf("%d %d \n", i,j);
            found = 1;
        }
        }
    }
    if (!found) {
        printf("Khong co phan tu nao co gia tri bang %d", x);
    }
    printf("\n");
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
}