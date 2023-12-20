#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *chuanHoa(char *name, char *email){
    char a[100][50];
    int n = 0;
    for(int i = 0; i < strlen(name); i++){
        name[i] = tolower(name[i]);
    }
    char *token = strtok(name, " ");
    while(token != NULL){
        strcpy(a[n], token); ++n;
        token = strtok(NULL, " ");
    }
    strcpy(email, a[n - 1]);
    int len = strlen(email);
    for(int i = 0; i < n - 1; i++){
        email[len] = a[i][0];
        ++len;
    }
    email[len] = '\0';
    strcat(email, "@28tech.com.vn");
    return email;
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
        out = fopen("email.txt", "w");
        char name[100], email[100];
        //Đọc mọi dòng trong file
        while(fgets(name, 100, in) != NULL){
            name[strlen(name) - 1] = '\0';
            fprintf(out, "%s\n", chuanHoa(name, email));
            strcpy(email, "");
        }
        fclose(in);
        fclose(out);
    }
    return 0;
}