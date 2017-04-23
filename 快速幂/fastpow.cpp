#include <cstdio>

#define mod 1000000007

int pow(int x,int y) {
	if (y==1) return x;
	int k=pow(x,y/2);
	k=k*k;
	if (y%2==1) k=k*x;
	return k;
}
int pow2(int x,int y) {
	int k=x,s=1;
	while(y) {
		if (y&1) s*=k;
		k*=k;
		y=y>>1;
	}
	return s;
}
int main() {
	int t,n,m;
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d",&n,&m);
		int k=pow(n,m),k2=pow2(n,m);
		printf("%d %d\n",k,k2);
	}
}
