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
        int a, b;
        cin >> a >> b;
        int n;
        cin >> n;
        double ans = INF;
        for(int i=0;i<n;i++) {
            int x, y, v;
            cin >> x >> y >> v;
            double dis = sqrt(double(x - a) * (x - a) + (y - b) * (y - b));
            ans = min(ans, dis / v);
        }
        cout << fixed << setprecision(10);
        cout << ans << endl;
    }
}