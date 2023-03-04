#include <stdio.h>
#include <conio.h>
#include <math.h>
struct DonThuc
{
    int HeSo;
    int SoMu;
};
void NhapDonThuc(DonThuc &a)
{
    printf("Nhap he so: ");
    scanf_s("%d",&a.HeSo);
    printf("Nhap so mu: ");
    scanf_s("%d",&a.SoMu);
}
void XuatDonThuc(DonThuc a)
{
    printf("%dX^%d",a.HeSo,a.SoMu);
}
//Tính tích 2 đơn thức
DonThuc Tich2DonThuc(DonThuc a, DonThuc b)
{
    DonThuc c;
    c.HeSo = a.HeSo * b.HeSo;
    c.SoMu = a.SoMu + b.SoMu;
    return c;
}
//Tính đạo hàm cấp 1 đơn thức
DonThuc DaoHamCap1(DonThuc a)
{
    DonThuc c;
    c.HeSo = a.HeSo * a.SoMu;
    c.SoMu = a.SoMu - 1;
    return c;
}
//Tính thương 2 đơn thức
DonThuc Thuong2DonThuc(DonThuc a, DonThuc b)
{
    DonThuc c;
    c.HeSo = a.HeSo / b.HeSo;
    c.SoMu = a.SoMu - b.SoMu;
    return c;
}
//Tính đạo hàm cấp k đơn thức
DonThuc DaoHamCapK(DonThuc a, int k)
{
    while (k!=0)
    {
        a = DaoHamCap1(a);
        k--;
    }
    return a;
}
//Tính giá trị đơn thức tại vị trí x=x0
double TinhGiaTriDonThuc(DonThuc a, int x)
{
    return a.HeSo*pow((double)x,a.SoMu);
}
//Định nghĩa toán tử (operator *) cho 2 đơn thức
DonThuc operator * (DonThuc a, DonThuc b)
{
    DonThuc c;
    c.HeSo = a.HeSo * b.HeSo;
    c.SoMu = a.SoMu + b.SoMu;
    return c;
}
//Định nghĩa toán tử (operator /) cho 2 đơn thức
DonThuc operator /(DonThuc a, DonThuc b)
{
    DonThuc c;
    c.HeSo = a.HeSo / b.HeSo;
    c.SoMu = a.SoMu - b.SoMu;
    return c;
}
