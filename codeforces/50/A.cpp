#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
#define MOD 1000000007
#define int long long
#define ld long double
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--) {
        int m, n;
        cin >> m >> n;
        int ans = m * (n / 2);
        if(n % 2 == 1) ans += m / 2;
        cout << ans << endl;
    }
}