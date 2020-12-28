#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
#define setpres cout << fixed << setprecision(10)
#define all(x) (x).begin(), (x).end()
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
        vector<vector<int>> v(n, vector<int>(n));
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cin >> v[i][j];
            }
        }
        vector<int> inp(n);
        for(int i=0;i<n;i++) {
            cin >> inp[i];
        }
        reverse(all(inp));
        vector<int> ans(n);
        vector<int> vis(n);
        for(int k=0;k<n;k++) {
            int num = inp[k];
            vis[num - 1] = 1;
            for(int i=0;i<n;i++) {
                for(int j=0;j<n;j++) {
                    v[i][j] = min(v[i][j], v[i][num - 1] + v[num - 1][j]);
                    if(vis[i] == 1 && vis[j] == 1) ans[k] += v[i][j];
                }
            }
        }
        reverse(all(ans));
        for(auto i : ans) {
            cout << i << " ";
        }
        cout << endl;
    }
}