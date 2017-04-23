#include<cstdio>

int n;
int a[10007];

void qsort(int l,int r) {
	int i=l,j=r,k=a[(l+r)/2];
	while(i<=j) {
		while(a[i]<k) i++;
		while(a[j]>k) j--;
		if (i<=j) {
			a[0]=a[i]; a[i]=a[j]; a[j]=a[0];
			i++; j--;
		}
	}
	if (l<j) qsort(l,j);
	if (i<r) qsort(i,r);
}

void qsort2(int l,int r) {
	if (l>=r) return;
	int i=l,j=r,k=a[i];
	while(i<j) {
		while(i<j && a[j]>=k) j--;
		a[i]=a[j];
		while(i<j && a[i]<=k) i++;
		a[j]=a[i];
	}
	a[i]=k;
	qsort2(l,i-1);
	qsort2(i+1,r);
}

int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	//qsort(1,n);
	qsort2(1,n);
	for (int i=1;i<=n;i++)
		printf("%d ",a[i]);
	printf("\n");
}
