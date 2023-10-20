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

	Str[0] = toupper
	
	for(int i =0; i< strlen(Str) -1; i++)
	{
		while (Str[i]==' ' && Str[i+1]==' ')
		{
			delete_char(Str, i);
		}
		if (Str[i]==' ' && Str[i+1]!=' ')
		{
			Str[i+1]=Str[i+1]-32; // Ascii
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
				if(S1[[i+j] != S2[j])
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


}