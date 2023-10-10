#include <stdio.h>

int timUSCLN(int a, int b)
{
	while (a != b)
	{
		if (a > b)
			a -= b;
		else
			b -= a;
	}
	return a;
}

int main()
{
	int a, b;

	printf("Nhap so thu nhat: ");
	scanf("%d", &a);

	printf("Nhap so thu hai: ");
	scanf("%d", &b);

	int USCLN = timUSCLN(a, b);

	printf("Uoc so chung lon nhat cua %d va %d la: %d\n", a, b, USCLN);

	return 0;
}