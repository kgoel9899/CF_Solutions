#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
int32_t main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        map<int, int> m;
        for(int i=0;i<n;i++) {
            cin >> a[i];
        }
        int s = 0;
        for(int i=0;i<n;i++) {
            cin >> b[i];
            s += b[i];
        }
        int ans = s;
        for(int i=0;i<n;i++) {
            m[a[i]] += b[i];
        }
        for(auto i : m) {
            s -= i.second;
            ans = min(ans, max(i.first, s));
        }
        cout << ans << endl;
    }
}