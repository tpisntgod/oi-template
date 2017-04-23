#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define ll long long
#define M 10000007

using namespace std;

struct data {
	int y,next;
} e[10007];
int a[1007],vis[1007],s[1007],ls[1007];
int main() {
	int n,m,es=0;
	for (int i = 1; i<1007;i++)
		s[i] = -1;
	cin>>n>>m;
	for (int i=1;i<=m;i++) {
		int x,y;
		es++;
		cin>>x>>y;
		e[es].y = y;
		e[es].next = ls[x];
		ls[x] = es;
		es++;
		e[es].y = x;
		e[es].next = ls[y];
		ls[y] = es;
	}
	int h,t;
	h=0; t=1; a[1] = 1; s[1] = 0; vis[1] =1;
	while (h<t) {
		h++;
		int k = ls[a[h]];
		while (k != 0) {
			if (!vis[e[k].y]) {
				vis[e[k].y] = 1;
				s[e[k].y] = s[a[h]] + 1;
				a[++t] = e[k].y;
			}
			k = e[k].next;
		}
	}
	for (int i=1;i<=n;i++)
		cout<<s[i] << " ";
	cout<<endl;
}
