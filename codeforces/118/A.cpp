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
	// cin >> t;	
	while(t--) {
		string s;
		cin >> s;
		int n = s.size();
		for(int i=0;i<n;i++) {
			char c = tolower(s[i]);
			if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') continue;
			cout << '.';
			cout << c;
		}
		cout << endl;
	}
}