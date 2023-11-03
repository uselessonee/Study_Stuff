#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>


bool Run = 1, Menuprinted = 0;

void Input_string(char* S1, char* S2)
{
    printf("Nhap chuoi S1:");
    gets(S1);
    
    fflush(stdin);

    printf("Nhap chuoi S2:");
    gets(S2);
}


// The name said it all
void delete_char(char *str, int i)
{

    for (; str[i+1] != '\0'; i++)
    {
        str[i] = str[i + 1];
    }

    str[i] = '\0';
}

void String_Norm(char *Str)
{

    while (Str[0] == ' ')
    {
        delete_char(Str, 0);
    }

    Str[0] = toupper(Str[0]);
    
    int i;
    for (i = 0; Str[i+1] != '\0'; i++)
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

    while (Str[i + 1] == ' ')
    {
        delete_char(Str, 0);
    }

    printf("%s", Str);
}

int Count_S2_in_S1(char *S1, char *S2)
{
    int count = 0;

    for (int i = 0; S1[i] != '\0'; i++)
    {
        if (S1[i] == S2[0])
        {
            for (int j = 0; (S2[j] != '\0'); j++)
            {
                if (S1[i + j] != S2[j])
                {
                    break;
                }
                if (S2[j + 1] == '\0')
                {
                    count++;
                }
            }
        }
    }
    return count;
}

int Count_Char(char *Str)
{
    char x;
    int count = 0;

    printf("Nhap ky tu can tim:");
    scanf("%c", &x);

    x = tolower(x);


    for (int i = 0; Str[i] != '\0'; i++)
    {
        if (tolower(Str[i]) == x)
        {
            count++;
        }
    }
    return count;
}

int count_word(char *Str)
{
    int count;

    for (int i = 0; Str[i] != '\0'; i++)
    {
        if (Str[i] == ' ')
            count++;
    }

    return count+1;
}

void link_char(char *S1, char *S2)
{
    int leng;
    while(S1[leng] != '\0') leng++;
    for (int i = leng; S2[i - leng] != '\0'; i++)
    {
        S1[i] = S2[i - leng];
    }

    printf("%s", S1);
}

bool is_symmetrical(char *str)
{
    int length = strlen(str);
    int mid = length / 2;

    for (int i = 0; i < mid; i++)
    {
        if (str[i] != str[length - i - 1])
        {
            return false;
        }
    }

    return true;
}

void Reverse_String(char *str)
{
    int length = strlen(str);

    for (int i = length; i >= 0; i--)
    {
        printf("%c", str[i]);
    }
}

// Menu

void Menu()
{
    system("cls");
    printf("************************************\n");
    printf("** THAO TAC TREN CHUOI            **\n");
    printf("** 1. Nhap va chuan hoa chuoi     **\n");
    printf("** 2. Dem so tu trong chuoi       **\n");
    printf("** 3. Ghep chuoi                  **\n");
    printf("** 4. Kiem tra doi xung           **\n");
    printf("** 5. In chuoi dao nguoc          **\n");
    printf("** 0. Thoat                       **\n");
    printf("*************************************\n");
}



int main()
{
	char *S1, *S2;
	S1 = (char*)malloc(sizeof(char) * 50);
	S2 = (char*)malloc(sizeof(char) * 50);
    while (Run)
    {
        if (!Menuprinted)
        {
            Menu();
            Menuprinted = true;
        }


		//INPUT
		if (_kbhit())
		{
			switch (getch())
			{
			case '1':
				
				Input_string(S1,S2);
				printf("Chuoi S1 sau khi chuan hoa:\n");
				String_Norm(S1);
				printf("\nChuoi S1 sau khi chuan hoa:\n");
				String_Norm(S2);

				printf("\nEnter de tiep tuc\n");
				getch();
				break;
			case '2':
				printf("Dem so tu: %d", count_word(S1));
				printf("\nEnter de tiep tuc\n");
				getch();
				break;
			case '3':
				link_char(S1, S2);
				printf("\nEnter de tiep tuc\n");
				getch();
				break;
			case '4':
				if (is_symmetrical(S1))
					printf("S1 doi xung");
				else
					printf("S1 ko doi xung");
				printf("\nEnter de tiep tuc\n");
				getch();
				break;
			case '5':
				Reverse_String(S1);
				printf("\nEnter de tiep tuc\n");
				getch();
				break;
			case '0':
				Run = 0;
				break;
			default:
				break;
			}
			Menuprinted = false;
		}
    }
    free(S1);
    free(S2);
}