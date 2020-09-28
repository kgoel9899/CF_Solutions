#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
#define MOD 1000000007
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
int main() {
	fast;
	int t = 1;
	cin >> t;
	while(t--) {
		int n, x;
		cin >> n >> x;
		if(n <= 2) cout << 1 << endl;
		else {
			n -= 2;
			int tmp = n / x;
			if(n % x != 0) tmp++;
			cout << tmp + 1 << endl; 
		}
	}
}