#include <iostream>

using namespace std;

int main() {
	int n=1,k;
	while (n!=0) {
	long long s=1;
	cin>>n>>k;
	for (int i=n-k+1;i<=n;i++)
	  s*=i;
	for (int i=1;i<=k;i++)
	  s/=i;
	cout<<s<<endl;
    }
}
