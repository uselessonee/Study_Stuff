#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>

//The name said it all
void delete_char(char *str, int i) {
    int len = strlen(str);

    for (; i < len -1; i++)
    {
       str[i] = str[i+1];
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
	
	for(int i =0; i< strlen(Str) -1; i++)
	{
		while (Str[i]==' ' && Str[i+1]==' ')
		{
			delete_char(Str, i);
		}
		if (Str[i]==' ' && Str[i+1]!=' ')
		{
			Str[i+1]=toupper(Str[i+1]);
		}
	}
	
	if (Str[strlen(Str) -1] == ' ')
	{
		delete_char(Str, 0);
	}
	
	printf("%s", Str);
}


int Count_S2_in_S1(char* S1, char* S2)
{
	int count =0;

	for (int i =0; S1[i] != '\0'; i++)
	{
		if (S1[i] == S2[0])
		{
			for (int j =0; (S2[j] != '\0') ; j++)
			{
				if(S1[i+j] != S2[j])
				{
					break;
				}
				if(S2[j+1] == '\0')
				{
					count++;
				}
			}
		}
	}
	return count;
}


int Count_Char(char* Str)
{
	char x;
	int count =0;

	printf("Nhap ky tu can tim:");
	scanf("%c", &x);

	x = tolower(x);

	int leng = strlen(Str);

	for(int i =0; i< leng; i++)
	{
		if(tolower(Str[i]) == x)
		{
			count++;
		}
	}
	return count;
}

int count_word(char* Str)
{
	int count;

	for ( int i =0; Str[i] != '\0'; i++)
	{
		if (Str[i] == ' ') count++;
	}

	return count++;
}



void link_char(char* S1,char* S2)
{
	int leng = strlen(S1);
	for (int i = leng; S2[i-leng] != '\0'; i++)
	{
		S1[i] = S2[i-leng];
	}

	printf("%s", S1);
}

int main()
{
	char S1[50], S2[50];
	printf("Nhap chuoi S1:");
	gets(S1);
	
	printf("Nhap chuoi S2:");
	gets(S2);
	
	printf("Chuoi sau khi chuan hoa:");
	printf("\nS1:");String_Norm(S1);
	
	printf("\nS2:");String_Norm(S2);
	
	printf("\n %d", Count_S2_in_S1(S1,S2));
	
	
	printf("%d ", Count_Char(S1));

	printf("Dem tu:%d", count_word(S1));
}