#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
/*
Tevel: Tadataka.... I'm bored! Have you done your fucking job yet?
*/
/////////////Init subFunction and var/////////////////////
bool Print_Menu =true;

void Input_string(char* s)
{
    printf("Nhap chuoi:");
    gets(s);
}

void delete_char(char *S, int POS)
{
    POS;
    while(S[POS] != '\0' )
    {
        S[POS-1]= S[POS];
    }
}



/////////NORMALIZE A STRING////////////
void String_Norm(char *Str)
{
    //Del all the space in front
    while (Str[0] == ' ')
    {
        delete_char(Str, 0);
    }

    Str[0] = toupper(Str[0]);

    for (int i = 0; i < strlen(Str) - 1; i++)
    {
        while (Str[i] == ' ' && Str[i + 1] == ' ')
        {
            delete_char(Str, i);
        }
        if (Str[i] == ' ' && Str[i + 1] != ' ')
        {
            Str[i + 1] = toupper(Str[i + 1]);
        }
    }

    //check if the last character is a space
    if (Str[strlen(Str) - 1] == ' ')
    {
        delete_char(Str, 0);
    }

    printf("%s", Str);
}

//////////Count an Input Character in the string///////////////
int Count_Char(char *Str)
{
    char x;
    int count = 0;

    printf("Nhap ky tu can tim:");
    scanf("%c", &x);

    x = tolower(x);

    int leng = strlen(Str);

    for (int i = 0; i < leng; i++)
    {
        if (tolower(Str[i]) == x)
        {
            count++;
        }
    }
    return count;
}

///////////////////COUNT WORDS IN STRING//////////
int count_word(char *Str)
{
    int count=1;

    for (int i = 0; Str[i] != '\0'; i++)
    {
        if (Str[i] == ' ')
            count++;
    }

    return count;
}

int main()
{
    char *S;
    S= (char*)malloc(sizeof(char) *50);
    ////////////////MAIN LOOP/////////////////
    while (true)
    {
                //////////PRINT UI//////////
        if(Print_Menu)
        {
        system("cls");
        printf("************************************\n");
        printf("** THAO TAC TREN CHUOI            **\n");
        printf("** 1. Nhap va chuan hoa chuoi     **\n");
        printf("** 2. Nhap 1 ky tu va dem ky tu   **\n");
        printf("** 3. Dem so tu co trong chuoi    **\n");
        printf("** 0. Thoat                       **\n");
        printf("*************************************\n");
        Print_Menu = false;
        }
        /////////////Input/////////////
        if(_kbhit)
        {
            switch(getch())
            {
                case '0': return 0;
                case '1': Input_string(S); String_Norm(S); system("Pause"); Print_Menu =1; break;
                case '2': printf("%d \n",Count_Char(S)); system("Pause"); Print_Menu =1; break;
                case '3': count_word(S); system("Pause"); Print_Menu =1; break;
            }
        }
    }
}