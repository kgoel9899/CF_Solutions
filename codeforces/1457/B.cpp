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
        vector<int> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        int ans = INT_MAX;
        for(int i=1;i<=100;i++) {
            int j = 0, curr = 0;
            while(j < n) {
                if(v[j] != i) {
                    curr++;
                    j += k;
                } else j++;
            }
            ans = min(ans, curr);
        }
        cout << ans << endl;
    }
}