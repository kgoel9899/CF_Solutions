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
        vector<vector<int>> v(n + 1, vector<int>(n + 1));
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                cin >> v[i][j];
            }
        }
        int kk;
        cin >> kk;
        for(int k=1;k<=kk;k++) {
            int a, b, c;
            cin >> a >> b >> c;
            int ans = 0;
            for(int i=1;i<=n;i++) {
                for(int j=1;j<=n;j++) {
                    v[i][j] = min({v[i][j], v[i][a] + v[b][j] + c, v[i][b] + v[a][j] + c});
                }
            }
            for(int i=1;i<=n;i++) {
                for(int j=1;j<=n;j++) {
                    ans += v[i][j];
                }
            }
            cout << ans / 2 << " ";
        }
        cout << endl;
    }
}