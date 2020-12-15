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
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        // vector<int> ind(n);
        int ans = 0;
        for(int i=0;i<n;i++) {
            int ind = upper_bound(v.begin(), v.end(), v[i] + 2) - v.begin();
            // cout << v[i] << " " << ind << endl;
            ind--;
            int len = ind - i;
            if(len >= 2) ans += (len * (len - 1)) / 2;
        }
        cout << ans << endl;
    }
}