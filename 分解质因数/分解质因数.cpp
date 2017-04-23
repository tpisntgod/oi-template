#include<stdio.h>

int main() 
{
    int n,i,j,k,t;
    scanf("%d",&t);
    for (j=1;j<=t;j++)
    {
    scanf("%d",&n);
    i=2;
    while (n>1) 
	{
      while (n%i==0) 
	  {
        printf("%d ",i); n=n/i;
      }
      i++;      
    }
    printf("\n");
    }
    return 0;
}
