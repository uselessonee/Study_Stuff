#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main()
{
    FILE *file;
    char filename[67], ch;
    printf("Enter Filename :  ");
    gets(filename);
    file = fopen(filename, "w");
    
    if(file == NULL)
    {
        printf("Error \n");
        exit(1);
    }

    while ((ch = getch()) != '\r')
    {
        putc(ch, file);
    }
    fclose(file);
}