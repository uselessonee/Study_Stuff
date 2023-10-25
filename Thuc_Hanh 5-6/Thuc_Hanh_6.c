#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

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

void nhapThongTinSinhVien(struct Sinhvien *sv)
{
    printf("Nhap ma so sinh vien: ");
    fgets(sv->masv, sizeof(sv->masv), stdin);
    printf("Nhap ho ten sinh vien: ");
    fgets(sv->hoten, sizeof(sv->hoten), stdin);
    printf("Nhap nam sinh cua sinh vien: ");
    scanf("%d", &sv->namsinh);
    printf("Nhap gioi tinh cua sinh vien: ");
    fgets(sv->phai, sizeof(sv->phai), stdin);
    printf("Nhap nganh hoc cua sinh vien: ");
    fgets(sv->nganhhoc, sizeof(sv->nganhhoc), stdin);
    printf("Nhap ket qua hoc tap cuoi khoa cua sinh vien: ");
    scanf("%f", &sv->kqcuoikhoa);
    printf("Nhap xep loai cua sinh vien: ");
    fgets(sv->xeploai, sizeof(sv->xeploai), stdin);
    printf("Nhap que quan cua sinh vien: ");
    fgets(sv->quequan, sizeof(sv->quequan), stdin);
}

void xuatThongTinSinhVien(struct Sinhvien *sv)
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



void xepLoaiSinhVien(struct Sinhvien *ds, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (ds[i].kqcuoikhoa < 1.5)
        {
            strcpy(ds[i].xeploai, "Yếu");
        }
        else if (ds[i].kqcuoikhoa <= 2.5)
        {
            strcpy(ds[i].xeploai, "Trung bình");
        }
        else if (ds[i].kqcuoikhoa <= 3.0)
        {
            strcpy(ds[i].xeploai, "Khá");
        }
        else if (ds[i].kqcuoikhoa <= 3.8)
        {
            strcpy(ds[i].xeploai, "Giỏi");
        }
        else
        {
            strcpy(ds[i].xeploai, "Xuất sắc");
        }
    }
}

void xuatDanhSachSinhVien(struct Sinhvien *ds, int n)
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

void sapXepSinhVienTheoKQ(struct Sinhvien *ds, int n)
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

void timVaXuatSinhVienGioiXuatSac(struct Sinhvien *ds, int n)
{
    int i;
    printf("Danh sach sinh vien Gioi hoac Xuat sac:\n");
    for (i = 0; i < n; i++)
    {
        if (strcmp(ds[i].xeploai, "Gioi") == 0 || strcmp(ds[i].xeploai, "Xuat sac") == 0)
        {
            xuatThongTinSinhVien(&ds[i]);
        }
    }
}

void timVaXuatSinhVienTheoMASV(struct Sinhvien *ds, int n)
{
    char masv[10];
    int i;
    printf("Nhap ma so sinh vien can tim: ");
    fgets(masv, sizeof(masv), stdin);
    for (i = 0; i < n; i++)
    {
        if (strcmp(ds[i].masv, masv) == 0)
        {
            xuatThongTinSinhVien(&ds[i]);
            break;
        }
    }
    if (i == n)
    {
        printf("ko tim thay sinh vien co ma so la %s\n", masv);
    }
}

// tim và xuất thông tin sinh vien theo nhom NGANHHOC

void timVaXuatSinhVienTheoNGANHHOC(struct Sinhvien *ds, int n)
{
    char nganhhoc[30];
    int i;
    printf("Nhap nhom nganh hoc can tim: ");
    fgets(nganhhoc, sizeof(nganhhoc), stdin);
    for (i = 0; i < n; i++)
    {
        if (strcmp(ds[i].nganhhoc, nganhhoc) == 0)
        {
            xuatThongTinSinhVien(&ds[i]);
        }
    }
    if (i == n)
    {
        printf("ko tim thay sinh vien thuoc nhom nganh hoc la %s\n", nganhhoc);
    }
}

int main()
{
    printf("%d", HamChar());
}