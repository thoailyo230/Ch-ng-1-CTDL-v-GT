#include<stdio.h>
#include<conio.h>
//  Khai báo biểu diễn thông tin số phức
struct SoPhuc
{
	float PhanThuc;
	float PhanAo;
};

typedef struct SoPhuc SOPHUC;
void NhapSoPhuc(SOPHUC &);
void XuatSoPhuc(SOPHUC);

SOPHUC TinhTong2SoPhuc(SOPHUC, SOPHUC);
SOPHUC TinhHieu2SoPhuc(SOPHUC, SOPHUC);
SOPHUC TinhTich2SoPhuc(SOPHUC, SOPHUC);
SOPHUC TinhThuong2SoPhuc(SOPHUC, SOPHUC);

SOPHUC TinhLuyThuaBacN(SOPHUC, int);

//Nhập số phức
void NhapSoPhuc(SOPHUC &sp)
{
	printf("\nNhap phan thuc: ");
	scanf("%f", &sp.PhanThuc);

	printf("\nNhap phan ao: ");
	scanf("%f", &sp.PhanAo);
}

//Xuất số phức
void XuatSoPhuc(SOPHUC sp)
{
	printf("%.3f + %.3fi", sp.PhanThuc, sp.PhanAo);
}

// Tính tổng 2 số phức
SOPHUC TinhTong2SoPhuc(SOPHUC a, SOPHUC b)
{
	SOPHUC c;
	c.PhanThuc = a.PhanThuc + b.PhanThuc;
	c.PhanAo = a.PhanAo + b.PhanAo;
	return c;
}

// Tính hiệu 2 số phức
SOPHUC TinhHieu2SoPhuc(SOPHUC a, SOPHUC b)
{
	SOPHUC c;
	c.PhanThuc = a.PhanThuc - b.PhanThuc;
	c.PhanAo = a.PhanAo - b.PhanAo;
	return c;
}

// Tính tích 2 số phức

/*
(a + bi)(c + di) = (ac - bd) + (ad + bc)i
*/
SOPHUC TinhTich2SoPhuc(SOPHUC a, SOPHUC b)
{
	SOPHUC c;
	c.PhanThuc = a.PhanThuc * b.PhanThuc - a.PhanAo * b.PhanAo;
	c.PhanAo = a.PhanThuc * b.PhanAo + a.PhanAo * b.PhanThuc;
	return c;
}

// Tính thương 2 số phức

SOPHUC SoPhucLienHop(SOPHUC a)
{
	a.PhanThuc = -a.PhanThuc;
	return a;
}
SOPHUC TinhThuong2SoPhuc(SOPHUC a, SOPHUC b)
{
	/*SOPHUC c = TinhTich2SoPhuc(a, SoPhucLienHop(b));
	float d = b.PhanAo * b.PhanAo + b.PhanThuc * b.PhanThuc;
	c.PhanThuc /= d;
	c.PhanAo /= d;
	return c;*/

	SOPHUC c;
    c.PhanThuc = (a.PhanThuc * b.PhanThuc + a.PhanAo * b.PhanAo) / (b.PhanThuc * b.PhanThuc + b.PhanAo * b.PhanAo);    
    c.PhanAo = (b.PhanThuc * a.PhanAo - b.PhanAo * a.PhanThuc) / (b.PhanThuc * b.PhanThuc + b.PhanAo * b.PhanAo);
	return c;
}	

SOPHUC TinhLuyThuaBacN(SOPHUC a, int n)
{
	while(n != 0)
	{
		a = TinhTich2SoPhuc(a, a);
		n--;
	}
	return a;
}
int main()
{
	SOPHUC a, b;
	NhapSoPhuc(a);
	XuatSoPhuc(a);

	NhapSoPhuc(b);
	XuatSoPhuc(b);

	SOPHUC tong = TinhTong2SoPhuc(a, b);
	SOPHUC hieu = TinhHieu2SoPhuc(a, b);
	SOPHUC tich = TinhTich2SoPhuc(a, b);
	SOPHUC thuong = TinhThuong2SoPhuc(a, b);
	SOPHUC luythua = TinhLuyThuaBacN(a, 2);

	printf("\nTinh tong 2 so phuc: ");
	XuatSoPhuc(tong);

	printf("\nTinh hieu 2 so phuc: ");
	XuatSoPhuc(hieu);

	printf("\nTinh tich 2 so phuc: ");
	XuatSoPhuc(tich);

	printf("\nTinh thuong 2 so phuc: ");
	XuatSoPhuc(thuong);

	printf("\nLuy thua bac 2 cua so phuc: ");
	XuatSoPhuc(luythua);

	getch();
	return 0;
}
