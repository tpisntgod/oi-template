#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int k=-1;
char pre[27],in[27];

void findpost(int l,int r) {
	if (l>r) return;
	k++;
	for (int i=l;i<=r;i++)
		if (pre[k] == in[i]) {
			findpost(l,i-1);
			findpost(i+1,r);
			printf("%c",in[i]);
			break;
		}
}
int main() {
	while(scanf("%s%s",pre,in)==2) {
		findpost(0,strlen(pre)-1);
		printf("\n");
		k=-1;
	}
}
