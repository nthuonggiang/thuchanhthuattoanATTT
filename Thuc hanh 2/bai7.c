#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int a,b;
    printf("a= ");
    scanf("%d",&a);
    printf("b= ");
    scanf("%d",&b);
    int m = a, n = b;
    int q,r,x,y,x1=0,x2=1,y1=1,y2=0;
    while(b > 0)
    {
        q = a / b;
        r = a % b;
        x = x2 - q*x1;
        y = y2 - q*y1;
        a=b, b=r;
        x2=x1;x1=x;y2=y1;y1=y;
    }
    printf("GCD( %d , %d ) = %d",m,n,a);
    return 0;
}

