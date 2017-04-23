#include <iostream>
	
using namespace std;
int main() {
	int n;
	int s[17];
	scanf("%d",&n);
	int all = 1 << n;
	for (int i = 0; i < all;i++) {
		int t=i;
		for (int j = 0;j < n;j++) {
			s[j] =t & 1;
			t>>=1;
		}
		for (int j=0;j<n;j++)
			cout<<s[j];
		cout<<endl;
	}
}
