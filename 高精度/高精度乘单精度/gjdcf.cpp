#include<stdio.h>

int a[107];
int main()
{
    int i,j,n,l,g,k;
    scanf("%d%d",&k,&n);  //k^n
    a[100]=1; l=1;
    g=0;
    for (i=1;i<=n;i++)
    {
      for (j=100;j>=1;j--)
      {
        a[j]=a[j]*k+g;
        g=a[j]/10;
        a[j]=a[j]%10;
      }
    }
    i=1;
    while (a[i]==0) i++;
    for (j=i;j<=100;j++)
      printf("%d",a[j]);
    printf("\n");
    return 0;
}
