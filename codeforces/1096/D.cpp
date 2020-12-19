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
    // cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        int a = 0, b = 0, c = 0, d = 0;
        for(int i=0;i<n;i++) {
            if(s[i] == 'h') a += v[i];
            else if(s[i] == 'a') b = min(a, b + v[i]);
            else if(s[i] == 'r') c = min({a, b, c + v[i]});
            else if(s[i] == 'd') d = min({a, b, c, d + v[i]});
        }
        cout << d << endl;
    }
}