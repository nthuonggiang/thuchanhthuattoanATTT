#include<stdio.h>
#include<math.h>

void nhapMang(int A[], int t)
{
    for (int i=0; i<t; i++)
    {
        printf("Nhap phan tu %d: ", i);
        scanf("%d", &A[i]);
    }
}
void congChinhXacBoi(int A[],int B[],int C[],int W,int t)
{
    int e=0;
    for(int i=t-1;i>=0;i--)
    {

        if(i==0)
        {
            C[i]=(A[i]+B[i])% (int)pow(2,W)+e;
        }
        if(A[i]+B[i] >=0 && A[i]+B[i] < pow(2,W))
        {
            C[i]=(A[i]+B[i])% (int)pow(2,W)+e;
            e=0;
        }
        else
        {
            C[i]=(A[i]+B[i])% (int)pow(2,W)+e;
            e=1;
        }
    }
}

void truChinhXacBoi(int A[],int B[],int D[],int W,int t)
{
    int e=0;
    for(int i=t-1;i>=0;i--)
    {
        if(A[i]-B[i]>0 && A[i]-B[i]< pow(2,W))
        {
            D[i]=(A[i]-B[i])% (int)pow(2,W)- e;
            e=0;
        }
        else if(A[i]-B[i] <0 ||  A[i]-B[i] > pow(2,W))
        {
            D[i]=abs(pow(2,W)-abs(A[i]-B[i]-e));
            e=1;
        }
        else
        {
            D[i]=abs(pow(2,W)-abs(A[i]-B[i]-e));
            e=0;
        }
    }
}

void ketQua(int t,int C[])
{
    for(int i=0;i<t;i++)
    {
        printf("%d\t",C[i]);
    }
}
int main() {
    int A[50],B[50],C[50],D[50];

    int W;
    printf("Nhap so W: ");
    scanf("%d",&W);
    int t;
    printf("Nhap so phan tu mang: ");
    scanf("%d",&t);
    printf("\nNhap mang A:\n");
    nhapMang(A,t);
    printf("\nNhap mang B:\n");
    nhapMang(B,t);
    congChinhXacBoi(A,B,C,W,t);
    printf("\nKet qua tong: ");
    ketQua(t,C);
    truChinhXacBoi(A,B,D,W,t);
    printf("\nKet qua hieu: ");
    ketQua(t,D);
}
