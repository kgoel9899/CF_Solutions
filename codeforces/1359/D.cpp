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
        vector<int> v(n);
        set<int> s;
        for(int i=0;i<n;i++) {
            cin >> v[i];
            s.insert(v[i]);
        }
        int ans = 0;
        for(int i=1;i<=30;i++) {
            if(s.count(i) > 0) {
                int curr = 0;
                for(auto j : v) {
                    if(j > i) curr = 0;
                    else {
                        curr += j;
                        curr = max(curr, 0ll);
                    }
                    ans = max(ans, curr - i);
                }
            }
        }
        cout << ans << endl;
    }
}