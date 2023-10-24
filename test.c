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
    printf("Nhập mã số sinh viên: ");
    fgets(sv->masv, sizeof(sv->masv), stdin);
    printf("Nhập họ tên sinh viên: ");
    fgets(sv->hoten, sizeof(sv->hoten), stdin);
    printf("Nhập năm sinh của sinh viên: ");
    scanf("%d", &sv->namsinh);
    printf("Nhập giới tính của sinh viên: ");
    fgets(sv->phai, sizeof(sv->phai), stdin);
    printf("Nhập ngành học của sinh viên: ");
    fgets(sv->nganhhoc, sizeof(sv->nganhhoc), stdin);
    printf("Nhập kết quả học tập cuối khóa của sinh viên: ");
    scanf("%f", &sv->kqcuoikhoa);
    printf("Nhập xếp loại của sinh viên: ");
    fgets(sv->xeploai, sizeof(sv->xeploai), stdin);
    printf("Nhập quê quán của sinh viên: ");
    fgets(sv->quequan, sizeof(sv->quequan), stdin);
}

void xuatThongTinSinhVien(struct Sinhvien *sv)
{
    printf("Mã số sinh viên: %s\n", sv->masv);
    printf("Họ tên sinh viên: %s\n", sv->hoten);
    printf("Năm sinh của sinh viên: %d\n", sv->namsinh);
    printf("Giới tính của sinh viên: %s\n", sv->phai);
    printf("Ngành học của sinh viên: %s\n", sv->nganhhoc);
    printf("Kết quả học tập cuối khóa của sinh viên: %.2f\n", sv->kqcuoikhoa);
    printf("Xếp loại của sinh viên: %s\n", sv->xeploai);
    printf("Quê quán của sinh viên: %s\n", sv->quequan);
}

// Xếp loại sinh viên

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
    printf("| Mã số sinh viên | Họ tên | Năm sinh | Giới tính | Ngành học | Kết quả học tập cuối khóa | Xếp loại | Quê quán |");
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
    printf("Danh sách sinh viên Giỏi hoặc Xuất sắc:\n");
    for (i = 0; i < n; i++)
    {
        if (strcmp(ds[i].xeploai, "Giỏi") == 0 || strcmp(ds[i].xeploai, "Xuất sắc") == 0)
        {
            xuatThongTinSinhVien(&ds[i]);
        }
    }
}

void timVaXuatSinhVienTheoMASV(struct Sinhvien *ds, int n)
{
    char masv[10];
    int i;
    printf("Nhập mã số sinh viên cần tìm: ");
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
        printf("Không tìm thấy sinh viên có mã số là %s\n", masv);
    }
}

// Tìm và xuất thông tin Sinh viên theo nhóm NGANHHOC

void timVaXuatSinhVienTheoNGANHHOC(struct Sinhvien *ds, int n)
{
    char nganhhoc[30];
    int i;
    printf("Nhập nhóm ngành học cần tìm: ");
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
        printf("Không tìm thấy sinh viên thuộc nhóm ngành học là %s\n", nganhhoc);
    }
}

int main()
{
    printf("%d", HamChar());
}