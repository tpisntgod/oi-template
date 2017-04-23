#include<stdio.h>

int a[10007];
int main() 
{
    int n,i,j,k;
    scanf("%d",&n);
    a[0]=1; a[1]=1;
    for (i=2; i<=/*10000*/100; i++)
      if (a[i]==0)
      for (j=2*i; j<=10000; j=j+i)
        a[j]=1;
    for (i=1;i<=10000;i++)
      if (a[i]==0) printf("%d ",i);
    return 0;
}
