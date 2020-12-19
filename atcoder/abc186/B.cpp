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
        int h, w;
        cin >> h >> w;
        vector<vector<int>> v(h, vector<int>(w));
        int mn = INF;
        for(int i=0;i<h;i++) {
            for(int j=0;j<w;j++) {
                cin >> v[i][j];
                mn = min(mn, v[i][j]);
            }
        }
        int ans = 0;
        for(int i=0;i<h;i++) {
            for(int j=0;j<w;j++) {
                ans += v[i][j] - mn;
            }
        }
        cout << ans << endl;
    }
}