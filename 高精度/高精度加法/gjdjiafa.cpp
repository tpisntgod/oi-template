#include<stdio.h>
#include<cstring>

int a[101][207];
int main()
{
	int m,d,i,j,k;
	/*
	  for (i=100;i>=1;i--)
	  {
	    a[i]=a[i]+b[i];
	    a[i-1]=a[i-1]+a[i]/10;
	    a[i]=a[i]%10;
	  }
	*/
	while (1)
	{
	  scanf("%d%d",&m,&d);
	  memset(a,0,sizeof(a));
	  if (m==0 && d==0) break;
	  for (i=0;i<m;i++) a[i][200]=i+1;
	  for (i=m;i<=d;i++)
	    for (j=200;j>=1;j--)
			  {
				a[i][j]+=a[i-1][j]+a[i-m][j];
			    a[i][j-1]=a[i][j-1]+a[i][j]/10;
			    a[i][j]=a[i][j]%10;
			  }
		i=1;
    while (a[d][i]==0) i++;
    for (j=i;j<=200;j++)
		  printf("%d",a[d][j]);
		printf("\n");
	}
}
