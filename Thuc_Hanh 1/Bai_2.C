#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

long tinhgiaithua(int n)
{
	int i;
	long factor=1;
	for(i =1;i<= n; i++)
	{
		factor = factor * i;
	}
	return factor;
}
int main()
{
	int n; 
	scanf("%d", &n);
	
	printf("Gia thua cua %d la: %lli", n,tinhgiaithua(n));
	return 0;
}