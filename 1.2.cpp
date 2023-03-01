#include<stdio.h>
#include<conio.h>
//Khai báo hỗn số trong toán học
struct Honso
{
   int Phannguyen, TuPhanso, MauPhanso;
    /* data */
};
typedef struct Honso HONSO;
void NhapHonSo(HONSO &);
void XuatHonso(HONSO);

void NhapHonSo(HONSO &ps)
{
    printf("\nNhap Vao Phan Nguyen: ");
    scanf("%d" , &ps.Phannguyen);
      do
      {
    printf("\nNhap Vao TuPhanso");
    scanf("%d" , &ps.TuPhanso);
    printf("\nNhap Vao MauPhanso");
    scanf("%d" , &ps.MauPhanso);
        if(ps.MauPhanso == 0)
        {
            printf("\nMauPhanso phai khac 0. Xin kiem tra lai !");
        }
    }while(ps.MauPhanso == 0);

}
void XuatHonso(HONSO ps)
{
    printf("%d %d/%d", ps.Phannguyen, ps.TuPhanso, ps.MauPhanso);
}
int main()
{
    HONSO ps;
    NhapHonSo(ps);
    XuatHonso(ps);

    

    getch();
    return 0;
}


