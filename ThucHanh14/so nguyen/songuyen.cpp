#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int nt(int n){
    if(n < 2) return 0;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0) return 0;
    }
    return 1;
}

int main(){
    FILE *in;
    in = fopen("number.txt", "r");
    if(in == NULL){
        printf("File not found !\n");
    }
    else{
        FILE *out;
        out = fopen("prime.txt", "w");
        int n, dem = 0;
        while(fscanf(in, "%d", &n) != -1){
            if(nt(n)){
                ++dem;
                fprintf(out, "%d ", n);
            }
            if(dem % 10 == 0)
                fprintf(out, "\n");
        }
        fclose(in);
        fclose(out);
    }
    return 0;
}