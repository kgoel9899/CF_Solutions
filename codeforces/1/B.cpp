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
		string s;
		cin >> s;
		int check = 0, i = 0;
		for(;i<s.size();i++) {
			if(s[i] >= '0' && s[i] <= '9') {
				check = 1;
				break;
			}
		}
		for(;i<s.size();i++) {
			if(s[i] >= 'A' && s[i] <= 'Z') {
				check = 0;
				break;
			}
		}
		if(check == 0) {
			int i = 1;
			string ans = "";
			while(s[i] != 'C') {
				ans += s[i];
				i++;
			}
			i++;
			int col = 0;
			while(i < s.size()) {
				col = col * 10 + (s[i] - '0');
				i++;
			}
			string temp = "";
			while(col) {
				col--;
				temp += char('A' + col % 26);
				col /= 26;
			} 
			reverse(temp.begin(), temp.end());
			ans = temp + ans;
			cout << ans << endl;
		} else {
			int i = 0;
			string col = "";
			while(true) {
				if(s[i] >= '0' && s[i] <= '9') break;
				col += s[i];
				i++;
			}
			int row = 0;
			while(i < s.size()) {
				row = row * 10 + (s[i] - '0');
				i++;
			}
			string ans = "";
			ans += 'R';
			ans += to_string(row);
			ans += 'C';
			int prod = 1, fin = 0;
			for(int i=col.size()-1;i>=0;i--) {
				fin += (col[i] - 'A' + 1) * prod;
				prod *= 26;
			}
			ans += to_string(fin);
			cout << ans << endl;
		}
	}
}