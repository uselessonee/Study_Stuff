#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(){
    FILE *in;
    in = fopen("hocsinh.txt", "r");
    if(in == NULL){
        printf("File not found !\n");
    }
    else{
        FILE *out;
        out = fopen("hocsinh_out.txt", "w");
        char name[200], diem[100];
        //Đọc mọi dòng trong file
        while(fgets(name, 200, in) != NULL){
            name[strlen(name) - 1] = '\0';
            double t, l, h;
            fscanf(in, "%lf %lf %lf", &t, &l, &h);
            fgetc(in);
            double tb = (t + l + h) / 3;
            fprintf(out, "%s %.1lf ", name, tb);
            if(tb >= 9) fprintf(out, "XUAT SAC\n");
            else if(tb >= 8) fprintf(out, "GIOI\n");
            else if(tb >= 6.5) fprintf(out, "KHA\n");
            else if(tb >= 5) fprintf(out, "TRUNG BINH\n");
            else fprintf(out, "YEU");
        }
        fclose(in);
        fclose(out);
    }
    return 0;
}