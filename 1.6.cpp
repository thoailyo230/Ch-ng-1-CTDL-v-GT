#include<stdio.h>
#include<conio.h>
// khái niệm đa thức 1 biến trong toán học:P(x) = a.n.X^n + a.n-1.X^n-1 + … + a.1.X + a.0 

struct DaThuc
{
	float a[100];
	int n;
};
typedef struct DaThuc DATHUC;

void NhapDaThuc(DATHUC &);
void XuatDaThuc(DATHUC);

void NhapDaThuc(DATHUC &dt)
{
	printf("\nNhap bac da thuc: ");
	scanf("%d", &dt.n);
	for(int i = dt.n; i >= 0; i--)
	{
		float temp;
		printf("\nNhap he so: ");
		scanf("%f", &temp);
		dt.a[i] = temp;
	}
}

void XuatDaThuc(DATHUC dt)
{
	for(int i = dt.n; i >= 0; i--)
	{
		printf("%8.3fx^%d + ", dt.a[i], i);
	}
}

int main()
{
	DATHUC dt;
	NhapDaThuc(dt);
	XuatDaThuc(dt);

	getch();
	return 0;
}
