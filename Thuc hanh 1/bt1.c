#include <stdio.h>
#include <math.h>
void tinhMang(int t,int a,int w,int A[])
{
    for(int i = t,j = t-1; i >= 0; i--)
    {
        A[j] = a/(pow(2,(i-1)*w));
        a = a - (A[j]*(pow(2,(i-1)*w)));
        j--;
    }
}
void hienThiMang(int t,int A[])
{
    for(int i=t-1;i>=0;i--)
    {
        printf("%d ",A[i]);
    }
}
int main()
{
    int W;
    printf("Nhap so W: ");
    scanf("%d",&W);
    int a;
    printf("Nhap so nguyen a:");
    scanf("%d",&a);
    int P;
    printf("Nhap so p: ");
    scanf("%d",&P);
    int A[100];
    int m = ceil(log(P)/log(2));
    if(fmod(m,1)>0)
        m=(int)m +1;
    int t = ceil(m/W);
    if(fmod(t,1)>=0)
        t=(int)t +1;
    tinhMang(t,a,W,A);
    hienThiMang(t,A);
}
