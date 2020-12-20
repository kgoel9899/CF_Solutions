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
        if(n % 2 == 0) cout << (n / 2 + 1) * (n / 2 + 1) << endl;
        else cout << 2 * (n / 2 + 1) * (n / 2 + 2) << endl;
    }
}