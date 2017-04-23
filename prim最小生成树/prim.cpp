#include<cstdio>
#include<cstring>
#include<iostream>
#define maxl 100000000

using namespace std;

struct data{
	int y,v,next;
} a[10007];
int ls[107],d[107],vis[107];

int main() {
	int n,e,ans;
	while(scanf("%d",&n)!=EOF) {
		e=0; ans=0;
		memset(ls,0,sizeof(ls));
		memset(vis,0,sizeof(vis));
		for (int i=1;i<=n;i++) d[i]=maxl;
		for (int i=1;i<=n;i++)
			for(int j=1;j<=n;j++) {
				int dis;
				scanf("%d",&dis);
				a[++e].y=j;
				a[e].next=ls[i];
				a[e].v=dis;
				ls[i]=e;
			}
		int l;
		l=ls[1]; vis[1]=1;
		while (l!=0) {
			int y=a[l].y;
			if (a[l].v<d[y]) d[y]=a[l].v;
			l=a[l].next;
		}
		for (int i=1;i<n;i++) {
			int min=maxl,k;
			for (int j=1;j<=n;j++)
				if (!vis[j] && d[j]<min) {
					min=d[j];
					k=j;
				}
			vis[k]=1;
			ans+=min;
			l=ls[k];
			while (l!=0) {
				int y=a[l].y;
				if (a[l].v<d[y]) d[y]=a[l].v;
				l=a[l].next;
			}
		}
		printf("%d\n",ans);
	}
}
