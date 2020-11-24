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
        vector<int> v(n);
        map<int, vector<int>> m;
        for(int i=0;i<n;i++) {
            cin >> v[i];
            m[v[i]].push_back(i);
        }
        int ans = INT_MAX;
        for(auto i : m) {
            vector<int> vv = i.second;
            int curr = 0;
            int sz = vv.size();
            if(vv[0] != 0) curr++;
            for(int j=1;j<sz;j++) {
                if(vv[j] != vv[j - 1] + 1) curr++;
            }
            if(vv[sz - 1] != n - 1) curr++;
            ans = min(ans, curr);
        }
        cout << ans << endl;
    }
}