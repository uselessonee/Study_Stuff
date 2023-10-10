#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


int tinhdtHCN(int H, int W)
{
	return H*W;
}
int main ()
{
	int height, width;
	
	scanf("%d %d", &height, &width);
	
	printf("Dien tich HCN la %d", tinhdtHCN(height, width));
	
	return 0;
}