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
		int k;
		cin >> k;
		int a, b, flag = 0;
		for(int i=5;i<=k/2;i++) {
			a = i;
			if(k % a == 0 && k / a >= 5) {
				flag = 1;
				b = k / a;
				break;
			}
		}
		if(flag == 0) cout << -1 << endl;
		else {
			vector<char> v = {'a', 'e', 'i', 'o', 'u'};
			string temp = "";
			for(int i=0;i<b;i++) {
				temp += v[i % 5];
			}
			cout << temp;
			for(int i=1;i<a;i++) {
				temp = temp.substr(1);
				if(temp[b - 2] == 'a') temp += 'e';
				else if(temp[b - 2] == 'e') temp += 'i';
				else if(temp[b - 2] == 'i') temp += 'o';
				else if(temp[b - 2] == 'o') temp += 'u';
				else temp += 'a';
				cout << temp;
			}
			cout << endl;
		}
	}
}