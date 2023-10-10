#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


void hoanvi(int *a, int *b)
{
	
	int temp =*a;
	*a = *b;
	*b= temp;
}
int main()
{
	int a,b;
	scanf("%d %d", &a, &b);
	
	hoanvi(&a, &b);
	
	printf("a= %d",a);
	printf("b= %d", b);
}