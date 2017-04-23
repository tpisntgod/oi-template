#include<cstdio>
#include<iostream>
#include<cmath>

using namespace std;

int a[50007][20],b[50007][20];
int n,q;
void rmq() {
	//for (int j=1;j<20;j++)
	for (int j=1; (1<<j) <=n; j++)
		for (int i=1; i+(1<<j)-1 <= n;i++) {
		//if (i+(1<<j)-1 <= n) {
			a[i][j]=max(a[i][j-1],a[i+ ( 1<<(j-1) ) ][j-1]);
			b[i][j]=min(b[i][j-1],b[i+ ( 1<<(j-1) ) ][j-1]);
		}
}
int main() {
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++) {
		scanf("%d",&a[i][0]);
		b[i][0]=a[i][0];
	}
	rmq();
	while(q--) {
		int l,r,k,maxq,minq;
		scanf("%d%d",&l,&r);
		k=(int) ( log(r-l+1.0) / log(2.0) );
		maxq=max(a[l][k],a[r- (1<<k) +1][k]);
		minq=min(b[l][k],b[r- (1<<k) +1][k]);
		printf("%d\n",maxq-minq);
	}
}
