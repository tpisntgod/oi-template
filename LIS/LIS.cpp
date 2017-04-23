#include<iostream>
#include<cstdio>

using namespace std;

int a[100007],d[100007];

int binsearch(int k,int l,int r)
{
	int mid;
	while (l<=r)
	{
		mid=(l+r)/2;
		if (d[mid]<k && k<=d[mid+1])
		    return mid;
		else if (d[mid]<k) l=mid+1;
		else r=mid-1;
	}
	return 0;
}

int main()
{
	int t,n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	    scanf("%d",&a[i]);
	int len=1,j;
	d[1]=a[1];
	for (int i=2;i<=n;i++)
	{
		if (a[i]>d[len]) j=++len;
		else j=binsearch(a[i],1,len)+1;
		d[j]=a[i];
	}
	printf("%d\n",len);
	return 0;
}
