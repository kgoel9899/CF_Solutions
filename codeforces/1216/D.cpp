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
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        int diff = 0;
        vector<int> temp;
        for(int i=0;i<n-1;i++) {
            diff = v[n - 1] - v[i];
            if(diff != 0) temp.push_back(diff);
        }
        int gcd = -1;
        for(auto i : temp) {
            if(gcd == -1) gcd = i;
            else gcd = __gcd(gcd, i);
        }
        int ans = 0;
        for(auto i : temp) {
            ans += i / gcd;
        }
        cout << ans << " " << gcd << endl;
    }
}