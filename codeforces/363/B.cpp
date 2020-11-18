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
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        int sum = 0, mn = INT_MAX, ans = -1;
        for(int i=0;i<=n;i++) {
            if(i >= k) {
                if(sum < mn) {
                    mn = sum;
                    ans = i - k;
                }
                sum -= v[i - k];
            }
            if(i != n) sum += v[i];
        }
        cout << ans + 1 << endl;
    }
}