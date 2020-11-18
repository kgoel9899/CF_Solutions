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
    map<string, int> m;
    while(t--) {
        string s;
        cin >> s;
        if(m.find(s) == m.end()) cout << "OK" << endl;
        else {
            cout << s + to_string(m[s]) << endl;
            m[s + to_string(m[s])]++;
        }
        m[s]++;
    }
}