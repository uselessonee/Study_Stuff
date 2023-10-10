#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int tinhtong(int a, int b)
{
	return a+b;
}
int main()
{
	int a,b;
	
	scanf("%d", &a);
	scanf("%d", &b);
	
	printf("Tong cua %d va %d la: %d",a,b, tinhtong(a,b));
	return 0;
}