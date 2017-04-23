#include<cstdio>

int n;
int a[10000007],b[20000007];
const int con=10000000;

int getpo(int l,int r) {
	int i=l,j=r,k=a[i];
	while(i<j) {
		while(i<j && a[j]<=k) j--;
		a[i]=a[j];
		while(i<j && a[i]>=k) i++;
		a[j]=a[i];
	}
	a[i]=k;
	return i;
}

void findk(int k,int l,int r) {
	int p;
	p=getpo(l,r);
	if (p==k) {
		printf("%d\n",a[p]);
		return;
	}
	else if (p>k) findk(k,l,p-1);
		else findk(k,p+1,r);
}

int main() {
	int k,l=0;
	scanf("%d",&n);
	scanf("%d",&k);
	l=0;
	for (int i=1;i<=n;i++) {
		int h;
		scanf("%d",&h);
		if (b[h+10000000]==0) {
			a[++l]=h;
			b[h+10000000]=1;
		}
	}
	findk(k,1,l);
}
