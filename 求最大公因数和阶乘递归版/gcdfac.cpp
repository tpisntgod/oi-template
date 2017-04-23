#include<stdio.h>

int gcd(int m, int n) 
{
    if (m%n==0) return n;
    return gcd(n,m%n);
}

int fac(int p) 
{
    if (p<=0) return 1;
    return fac(p-1)*p;
}

int main(void) 
{
  int a,b,c;
  scanf("%d%d%d",&a,&b,&c);
  printf("%d %d\n",gcd(a, b),fac(c));
}
