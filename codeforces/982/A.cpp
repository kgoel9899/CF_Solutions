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
		int n;
		cin >> n;
		string s;
		cin >> s;
		if(n == 1) {
			if(s == "0") cout << "No" << endl;
			else cout << "Yes" << endl;
		} else {
			if(s[0] == '0' && s[1] == '0') cout << "No" << endl;
			else {
				if(s[0] == '1') {
					int ct = 0, flag = 0;
					for(int i=1;i<n;i++) {
						if(s[i] == '0') ct++;
						else {
							if(ct >= 3) {
								flag = 1;
								break;
							}
							ct = 0;
						}
					} 
					if(ct >= 2) flag = 1;
					for(int i=1;i<n;i++) {
						if(s[i] == s[i - 1] && s[i] == '1') {
							flag = 1;
							break;
						}
					}
					if(flag == 1) cout << "No" << endl;
					else cout << "Yes" << endl;
				} else {
					int ct = 0, flag = 0;
					for(int i=2;i<n;i++) {
						if(s[i] == '0') ct++;
						else {
							if(ct >= 3) {
								flag = 1;
								break;
							}
							ct = 0;
						}
					} 
					if(ct >= 2) flag = 1;
					for(int i=1;i<n;i++) {
						if(s[i] == s[i - 1] && s[i] == '1') {
							flag = 1;
							break;
						}
					}
					if(flag == 1) cout << "No" << endl;
					else cout << "Yes" << endl;
				}
			}
		}
	}
}