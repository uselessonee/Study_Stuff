#include <stdio.h>
#include <string.h>
#include <ctype.h>

//Hàm này chuẩn hóa từng từ : liNH => Linh
char* chuanHoaTu(char *s){
    s[0] = toupper(s[0]);
    for(int i = 1; i < strlen(s); i++){
        s[i] = tolower(s[i]);
    }
    return s;
}

char *chuanHoaTen(char *s, char *res){
    char *token = strtok(s, " ");
    while(token != NULL){
        //nối từ vào chuỗi kết quả res
        strcat(res, chuanHoaTu(token));
        token = strtok(NULL, " ");
        //Nếu chưa phải từ cuối thì nối thêm dấu cách
        if(token != NULL){
            strcat(res, " ");
        }
    }
    return res;
}

int main(){
    //Mo file
    FILE *in;
    in = fopen("sinhvien.txt", "r");
    if(in == NULL){
        printf("File not found !\n");
    }
    else{
        FILE *out;
        out = fopen("sinhvien_out.txt", "w");
        int n;
        fscanf(in, "%d", &n);
        fprintf(out, "%d\n", n);
        fgetc(in);
        char name[100], s[100];
        for(int i = 0; i < n; i++){
            //Doc file
            fgets(s, 100, in);
            s[strlen(s) - 1] = '\0';
            //Ghi file
            fprintf(out, "%s\n", chuanHoaTen(s, name));
            //reset xau name
            strcpy(name, "");
        }
        fclose(in);
        fclose(out);
    }
    return 0;
}