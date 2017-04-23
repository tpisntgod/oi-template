#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define ll long long

using namespace std;

priority_queue<int,vector<int>,greater<int> >q;
ll ans=0;
int n;

int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		int j;
		scanf("%d",&j);
		q.push(j);
	}
	while(q.size()!=1) {
		int a=q.top(); q.pop();
		int b=q.top(); q.pop();
		ans+=(a+b);
		q.push(a+b);
	}
	printf("%lld\n",ans);
}
