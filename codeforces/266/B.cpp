#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
#define MOD 1000000007
#define int long long
#define ld long double
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--) {
        int n, ti;
        cin >> n >> ti;
        string s;
        cin >> s;
        while(ti--) {
            int i = 0;
            while(i < n - 1) {
                if(s.substr(i, 2) == "BG") {
                    swap(s[i], s[i + 1]);
                    i += 2;
                } else i++;
            }
        }
        cout << s << endl;
    }
}