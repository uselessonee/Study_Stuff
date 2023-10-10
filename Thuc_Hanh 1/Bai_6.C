#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int kiemtraSNT(int n)
{
	int i;
	for (i = 2; i<= n/2; i++)
	{
		if (n % i ==0)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	int n;
	
	scanf("%d", &n);
	
	if(kiemtraSNT(n)==0)
	printf("%d ko phai la so nguyen to",n);
	else 	printf("%d la so nguyen to",n);
}