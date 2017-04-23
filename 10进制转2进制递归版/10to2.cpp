#include<stdio.h>

void dod(int n)
{
    int i;
    if (n==0) return;
    dod(n/2);
    printf("%d",n%2);
}
int main()
{
   int n;
   scanf("%d",&n);
   dod(n);
}
