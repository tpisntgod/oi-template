#include<stdio.h>

int main()
{
	int n,i,j,k,l;
	int a[107][107],b[107][107];
	while (scanf("%d",&n)!=EOF)
	{
		for (i=1;i<=n;i++)
		  for (j=1;j<=n;j++)
		    scanf("%d",&a[i][j]);
		for (i=1;i<=n;i++)
		  for (j=1;j<=n;j++)
		    scanf("%d",&b[i][j]);
		for (i=1;i<=n;i++)
		  for (j=1;j<=n;j++)
		  {
		    k=0;
		    for (l=1;l<=n;l++)
		      k=k+a[i][l]*b[l][j];
		    if (j!=n) printf("%d ",k); else printf("%d\n",k);
		  }
	}
}
