#include<stdio.h>
#include<math.h>

void tinhMang(int t,int a,int w,int A[])
{
    for(int i = t,j = t-1; i >= 0; i--)
    {
        A[j] = a/(pow(2,(i-1)*w));
        a = a - (A[j]*(pow(2,(i-1)*w)));
        j--;
    }
    for(int i=t-1;i>=0;i--)
    {
        printf("%d\t",A[i]);
    }
}

void tinhNhan(int t,int A[],int B[],int C[])
{
    for (int i = 0; i < sizeof(C); i++)
    {
        C[i] = 0;
    }
    int U=0,V=0,UV;
    for (int i = 0; i < t; i++)
    {
        U=0;
        for (int j = 0; j < t; j++)
        {
            UV =C[i+j]+A[i]*B[j]+U;
            U=UV/256;
            V=UV%256;
            C[i+j]=V;
        }
        C[i+t]=U;
    }
    for (int i = sizeof(C)-1; i >=0; i--)
    {
        printf("%d\t",C[i]);
    }
}

int main()
{
    int W;
    printf("Nhap so W: ");
    scanf("%d",&W);
    int a,b;
    printf("Nhap so nguyen a:");
    scanf("%d",&a);
    printf("Nhap so nguyen b:");
    scanf("%d",&b);
    int P;
    printf("Nhap so p: ");
    scanf("%d",&P);
    int A[100],B[100],C[100];
    int m = ceil(log(P)/log(2));
    if(fmod(m,1)>0)
        m=(int)m +1;
    int t = ceil(m/W);
    if(fmod(t,1)>=0)
        t=(int)t +1;
    tinhMang(t,a,W,A);
    printf("\n");
    tinhMang(t,b,W,B);
    printf("\n");
    tinhNhan(t,A,B,C);
}

