#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e18;
int32_t main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string t = "2020";
        if(s.substr(0, 4) == t || s.substr(n - 4) == t) {
            cout << "YES" << endl;
            continue;
        }
        if(s[0] + s.substr(n - 3) == t || s.substr(0, 3) + s[n - 1] == t) {
            cout << "YES" << endl;
            continue;
        }
        if(s.substr(0, 2) + s.substr(n - 2) == t) {
            cout << "YES" << endl;
            continue;
        }
        cout << "NO" << endl;
    }
}