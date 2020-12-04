#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e18;
int sum(int n) {
    return (n * (n + 1)) / 2;
}
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int ans = 0;
        while(n--) {
            int a, b;
            cin >> a >> b;
            ans += sum(b) - sum(a - 1);
        }
        cout << ans << endl;
    }
}