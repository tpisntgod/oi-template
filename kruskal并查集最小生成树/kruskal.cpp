#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct point{
	int x,y,v;
} a[10001];
int fa[101];
int n,m,ans,e;

int gz(const point &a,const point &b) {
	if (a.v<b.v) return 1;
	return 0;
}
int find(int x) {
	if (fa[x]==x) return x;
	fa[x]=find(fa[x]);
	return fa[x];
	/*
	if (fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
	*/
}
int main() {
	while(scanf("%d",&n)!=EOF) {
	ans=0; m=0; e=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) {
			int k;
			cin>>k;
			if (k>0) {
				m++;
				a[m].x=i; a[m].y=j; a[m].v=k;
			}
		}
	for (int i=1;i<=n;i++) fa[i]=i;
	sort(a+1,a+m+1,gz);
	for (int i=1;i<=m;i++) {
		int fx=find(a[i].x),fy=find(a[i].y);
		if (fx!=fy) {
			fa[fx]=fy;
			e++;
			ans+=a[i].v;
		}
		if (e == n-1) break;
	}
	cout<<ans<<endl;
	}
	return 0;
}
