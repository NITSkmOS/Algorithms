#include<stdio.h>
int euclidean_gcd(int a,int b)
{
    if(!b)
        return a;
    return euclidean_gcd(b,a%b);
}
int main()
{
    int x,y;
    printf("Enter two numbers of which gcd is to calculated: ");
    scanf("%d",&x);
    scanf("%d",&y);
    if(x==0 && y==0)
        printf("Error not defined\n");
    else if(!x)
        printf("Gcd of %d,%d is = %d\n",x,y,euclidean_gcd(y,x));
    else
        printf("Gcd of %d,%d is = %d\n",x,y,euclidean_gcd(x,y));
    return 0;
}
