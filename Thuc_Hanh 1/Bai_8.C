#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>


// check prime
bool KTNT(int n)
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


// sum al the prime nums
int TONGNT(int n)
{
	int i, sum=0;
	for (i =1; i<= n; i++)
	{
		if (KTNT(i)) sum += i;
	}
	
	return sum;
}


int main()
{
	int n;
	do
	{
		scanf("%d", &n);
	} while (n <0 || n > 20);
	
	system("cls");
	
		if(KTNT(n)==0)
	printf("%d ko phai la so nguyen to \n",n);
	else 	printf("%d la so nguyen to \n",n);
	
	printf("Tong cac so nguyen to tu 1 - %d la: %d",n, TONGNT(n));
}