#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

bool Run =1, MenuPrinted =0;
int n;

struct Sinhvien
{
    char masv[10];
    char hoten[30];
    int namsinh;
    char phai[10];
    char nganhhoc[30];
    float kqcuoikhoa;
    char xeploai[30];
    char quequan[30];
};

Sinhvien* sinh_vien;


void RANK_STUDENT(Sinhvien *ds, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (ds[i].kqcuoikhoa < 1.5)
        {
            strcpy(ds[i].xeploai, "Yeu");
        }
        else if (ds[i].kqcuoikhoa <= 2.5)
        {
            strcpy(ds[i].xeploai, "Trung binh");
        }
        else if (ds[i].kqcuoikhoa <= 3.0)
        {
            strcpy(ds[i].xeploai, "Kha");
        }
        else if (ds[i].kqcuoikhoa <= 3.8)
        {
            strcpy(ds[i].xeploai, "Gioi");
        }
        else
        {
            strcpy(ds[i].xeploai, "Xuat sac");
        }
    }
}

void Input_Student_Info(Sinhvien *sv)
{
	fflush(stdin);
    printf("Nhap ma so sinh vien: ");
    fgets(sv->masv, 10 , stdin); fflush(stdin);
    printf("Nhap ho ten sinh vien: ");
    fgets(sv->hoten, 30, stdin); fflush(stdin);
    printf("Nhap nam sinh cua sinh vien: ");
    scanf("%d", &sv->namsinh); fflush(stdin);
    printf("Nhap gioi tinh cua sinh vien: ");
    fgets(sv->phai, 10 , stdin); fflush(stdin);
    printf("Nhap nganh hoc cua sinh vien: ");
    fgets(sv->nganhhoc, 30 , stdin); fflush(stdin);
    printf("Nhap ket qua hoc tap cuoi khoa cua sinh vien: ");
    scanf("%f", &sv->kqcuoikhoa); fflush(stdin);
    
    RANK_STUDENT(sv, n);
    printf("Nhap que quan cua sinh vien: ");
    fgets(sv->quequan, 30 , stdin); fflush(stdin);
}

void Print_Student_Info(Sinhvien *sv)
{
    printf("Ma so sinh vien: %s\n", sv->masv);
    printf("Ho ten sinh vien: %s\n", sv->hoten);
    printf("Nam sinh cua sinh vien: %d\n", sv->namsinh);
    printf("Gioi tinh cua sinh vien: %s\n", sv->phai);
    printf("Nganh hoc cua sinh vien: %s\n", sv->nganhhoc);
    printf("Ket qua hoc tap cuoi khoa cua sinh vien: %.2f\n", sv->kqcuoikhoa);
    printf("Xep loai cua sinh vien: %s\n", sv->xeploai);
    printf("Que quan cua sinh vien: %s\n", sv->quequan);
}



void Print_Student_List(Sinhvien *ds)
{
    int i;
    printf("| Ma so sinh vien | Ho ten | Nam sinh | Gioi tinh | nganh hoc | Ket qua hoc tap cuoi khoa | Xep loai | Que quan |");
    printf("\n");
    for (i = 0; i < n; i++)
    {
        printf("| %-10s | %-15s | %-5d | %-10s | %-15s | %-10.2f | %-10s | %-15s |",
               ds[i].masv, ds[i].hoten, ds[i].namsinh, ds[i].phai, ds[i].nganhhoc, ds[i].kqcuoikhoa,
               ds[i].xeploai, ds[i].quequan);
        printf("\n");
    }
}

void Sort_Student_w_Result(Sinhvien *ds)
{
    int i, j;
    struct Sinhvien temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (ds[i].kqcuoikhoa > ds[j].kqcuoikhoa)
            {
                temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
}

void Find_Good_Student(Sinhvien *ds)
{
    int i;
    printf("Danh sach sinh vien Gioi hoac Xuat sac:\n");
    for (i = 0; i < n; i++)
    {
        if (strcmp(ds[i].xeploai, "Gioi") == 0 || strcmp(ds[i].xeploai, "Xuat sac") == 0)
        {
            Print_Student_Info(&ds[i]);
        }
    }
}

void Find_Student_Through_ID(Sinhvien *ds)
{
    char masv[10];
    int i;
    printf("Nhap ma so sinh vien can tim: ");
    fgets(masv, sizeof(masv), stdin);
    
    
    for (i = 0; i < n; i++)
    {
        if (strcmp(ds[i].masv, masv) == 0)
        {
            Print_Student_Info(&ds[i]);
            break;
        }
    }
    if (i == n)
    {
        printf("ko tim thay sinh vien co ma so la %s\n", masv);
    }
}



void Find_Student_Through_SUBJECT(Sinhvien *ds, int n)
{
    char nganhhoc[30];
    int i;
    printf("Nhap nhom nganh hoc can tim: ");
    fgets(nganhhoc, sizeof(nganhhoc), stdin);
    for (i = 0; i < n; i++)
    {
        if (strcmp(ds[i].nganhhoc, nganhhoc) == 0)
        {
            Print_Student_Info(&ds[i]);
        }
    }
    if (i == n)
    {
        printf("ko tim thay sinh vien thuoc nhom nganh hoc la %s\n", nganhhoc);
    }
}


void Menu()
{
	system("cls");
	printf("****************************************************************\n");
	printf("**            CHUONG TRINH QUAN LY SINH VIEN                  **\n");
	printf("**            1. Nhap DS SINH VIEN                            **\n");
	printf("**            2. IN DS SINH VIEN                              **\n");
	printf("**            3. SAP XEP THEO KQ cuoikhoa                     **\n");
	printf("**            4. IN SV GIOI, XUAT SAC                         **\n");
	printf("**            5. TIM KIEM SV THEO MSV                         **\n");
	printf("**            0. THOAT                                        **\n");
	printf("****************************************************************\n");
	
	MenuPrinted =1;
}


void Input()
{
    // Input
    if (_kbhit())
    {
        switch (getch())
        {
        case '1':
        	
        	printf("Nhap so luong sinh vien");
        	scanf("%d", &n);

            sinh_vien = (Sinhvien*) malloc(sizeof(Sinhvien) * n);


            for (int i =0; i< n; i++)
            {
                Input_Student_Info(&sinh_vien[i]);
            }
            
            printf("\nEnter de tiep tuc\n");
            getch();
            break;
        case '2':
        	Print_Student_List(sinh_vien);
            getch();
            break;
        case '3':
        	Sort_Student_w_Result(sinh_vien);
            getch();
            break;
        case '4':
        	Find_Good_Student(sinh_vien);
            printf("\nEnter de tiep tuc\n");
            getch();
            break;
        case '5':
    		Find_Student_Through_ID(sinh_vien);
            printf("\nEnter de tiep tuc\n");
            getch();
            break;
        case '0':
            break;
        default:
            break;
        }
        
        MenuPrinted =0;

    }
}

int main()
{	
	while (Run)
	{
		if(!MenuPrinted )Menu();
		Input();
	}
	free(sinh_vien);
}