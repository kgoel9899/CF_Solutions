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
        vector<int> v(n);
        int sum = 0, mx = 0;
        for(int i=0;i<n;i++) {
            cin >> v[i];
            sum += v[i];
            mx = max(mx, v[i]);
        }
        if(sum <= mx * (n - 1)) cout << mx * (n - 1) - sum << endl;
        else {
            if(sum % (n - 1) == 0) cout << 0 << endl;
            else cout << (n - 1) * (sum / (n - 1) + 1) - sum << endl;
        }
    }
}