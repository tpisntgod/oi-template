#include<iostream>
#include<cstdio>
#include<cstring>
#define maxl 100000000

using namespace std;

int a[1007][1007],d[1007],v[1007];
int main() {
	int n,t;
	scanf("%d%d",&t,&n);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			a[i][j]=maxl;
	for (int i=1;i<=t;i++) {
		int x,y,dis;
		scanf("%d%d%d",&x,&y,&dis);
		if (dis<a[x][y]) {
			a[x][y]=dis;
			a[y][x]=dis;
		}
	}
	for (int i=1;i<=n;i++)
		d[i]=a[1][i];
	v[1]=1;
	for (int i=1;i<=n;i++) {
		int min=maxl,l=0;
		for (int j=1;j<=n;j++)
			if (!v[j] && d[j]<min) {
				min=d[j];
				l=j;
			}
		if (l==0) break;
		v[l]=1;
		for (int j=1;j<=n;j++)
			if (!v[j] && d[l]+a[l][j]<d[j])
				d[j]=d[l]+a[l][j];
	}
	printf("%d\n",d[n]);
}
