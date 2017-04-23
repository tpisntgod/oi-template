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

int f[3007][3007];
int a[3007],vis[3007],s[3007];
int main() {
	int n,m;
	for (int i = 1; i<1007;i++)
		s[i] = -1;
	cin>>n>>m;
	for (int i=1;i<=m;i++) {
		int x,y;
		cin>>x>>y;
		f[x][y] = 1;
		f[y][x] = 1;
	}
	int h,t;
	h=0; t=1; a[1] = 1; s[1] = 0; vis[1] = 1;
	while (h<t) {
		h++;
		int k = a[h];
		for (int i=1;i<=n;i++) {
			if (f[k][i] && !vis[i]) {
				vis[i] = 1;
				a[++t] = i;
				s[i] = s[k] + 1;
			}
		}
	}
	for (int i=1;i<=n;i++)
		cout<<s[i] << " ";
	cout<<endl;
}
