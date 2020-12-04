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
        int n, x;
        cin >> n >> x;
        vector<int> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        int ans = 0;
        if(is_sorted(v.begin(), v.end())) cout << 0 << endl;
        else {
            for(int i=0;i<n;i++) {
                if(v[i] > x) {
                    swap(v[i], x);
                    ans++;
                }
                if(is_sorted(v.begin() + i, v.end())) break;
            }
            if(is_sorted(v.begin(), v.end())) cout << ans << endl;
            else cout << -1 << endl;
        }
    }
}