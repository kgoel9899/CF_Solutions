#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
#define setpres cout << fixed << setprecision(10)
#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e18;
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--) {
        int n, x;
        cin >> n >> x;
        if(n <= x) cout << min(n, x - n) << endl;
        else if(n % x == 0) cout << 0 << endl;
        else {
            int a = (n / x) * x;
            int b = (n / x + 1) * x;
            cout << min(n - a, b - n) << endl;
        }
    }
}