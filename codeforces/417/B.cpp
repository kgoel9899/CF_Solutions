#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e18;
const int N = 1e5 + 5;
vector<int> v(N, -1);
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--) {
        // int n, k;
        // cin >> n >> k;
        // string s = to_string(n);
        // int i = (int)s.size() - 1;
        // string ans = "";
        // for(;i>=0;i--) {
        //     if(s[i] == '0') {
        //         k--;
        //         ans += s[i];
        //     }
        //     if(k <= 0) break;
        // }
        // cout << ans << endl;
        int n;
        cin >> n;
        int flag = 0;
        for(int i=0;i<n;i++) {
            int x, k;
            cin >> x >> k;
            if(x <= v[k] + 1) v[k] = max(v[k], x);
            else {
                flag = 1;
                break;
            }
        }
        if(flag == 1) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}