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
        int n, k;
        cin >> n >> k;
        vector<vector<int>> v(n, vector<int>(2));
        for(int i=0;i<n;i++) {
            cin >> v[i][0] >> v[i][1];
        }
        int flag = 0;
        for(int i=0;i<n;i++) {
            int ct = 0;
            for(int j=0;j<n;j++) {
                int dist = abs(v[j][0] - v[i][0]) + abs(v[j][1] - v[i][1]);
                if(dist <= k) ct++;
            }
            if(ct == n) {
                flag = 1;
                break;
            }
        }
        if(flag == 0) cout << -1 << endl;
        else cout << 1 << endl;
    }
}