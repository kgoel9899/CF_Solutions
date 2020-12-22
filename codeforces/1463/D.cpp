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
        vector<int> vis(2 * n + 1);
        vector<int> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
            vis[v[i]] = 1;
        }
        vector<int> mn(n + 1), mx(n + 1);
        mn[0] = 1;
        mx[0] = 1;
        int ct = 0, ct1 = 0;
        int j = 1;
        for(int i=1;i<=2*n;i++) {
            if(vis[i] == 1) {
                j = max(j, i + 1);
                while(j <= 2 * n) {
                    if(vis[j] == 0) {
                        ct++;
                        mn[ct] = 1;
                        vis[j] = -1;
                        j++;
                        break;
                    } else j++;
                }
            }
        }
        for(int x=0;x<=2*n;x++) {
            if(vis[x] == -1) vis[x] = 0;
        }
        j = 2 * n - 1;
        for(int i=2*n;i>=0;i--) {
            if(vis[i] == 1) {
                j = min(j, i - 1);
                while(j >= 1) {
                    if(vis[j] == 0) {
                        ct1++;
                        mx[ct1] = 1;
                        vis[j] = -1;
                        j--;
                        break;
                    } else j--;
                }
            }
        }
        int ans = 0;
        for(int i=0;i<=n;i++) {
            if(mn[i] + mx[n - i] == 2) ans++;
        }
        cout << ans << endl;
    }
}