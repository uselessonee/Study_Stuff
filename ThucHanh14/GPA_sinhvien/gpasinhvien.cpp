#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct SinhVien{
    char ten[100];
    char lop[20];
    char ngaysinh[50];
    double gpa;
};

typedef struct SinhVien SinhVien;

int cmp(const void *a, const void *b){
    SinhVien *x = (SinhVien*)a;
    SinhVien *y = (SinhVien*)b;
    if(x->gpa > y->gpa)
        return -1;
    return 1;
}

int main(){
    FILE *in;
    SinhVien a[1000]; int n = 0;
    in = fopen("sinhvien.txt", "r");
    if(in == NULL){
        printf("File not found !\n");
    }
    else{
        FILE *out;
        out = fopen("sinhvien_out.txt", "w");
        char data[200], email[100];
        //Đọc mọi dòng trong file
        while(fgets(data, 200, in) != NULL){
            data[strlen(data) - 1] = '\0';
            //tach thong tin
            int stt = 0;
            char *token = strtok(data, ",");
            while(token != NULL){
                ++stt; // stt = 1 : ten, 2 : lop, 3 : ngaysinh, 4 : gpa
                if(stt == 1){
                    strcpy(a[n].ten, token);
                }
                else if(stt == 2){
                    strcpy(a[n].lop, token);
                }
                else if(stt == 3){
                    strcpy(a[n].ngaysinh, token);
                }
                else{
                    a[n].gpa = atof(token);
                }
                token = strtok(NULL, ",");
            }
            ++n; // tang so luong sinh vien
        }
        //Sap xep danh sach
        qsort(a, n, sizeof(SinhVien), cmp);
        //Ghi file
        for(int i = 0; i < n; i++){
            fprintf(out, "%s,%s,%s,%.1lf\n", a[i].ten, a[i].lop, a[i].ngaysinh, a[i].gpa);
        }
        fclose(in);
        fclose(out);
    }
    return 0;
}