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
        int n, k;
        cin >> n >> k;
        int ans = INT_MIN;
        while(n--) {
            int a, b;
            cin >> a >> b;
            if(b > k) ans = max(ans, a - (b - k));
            else ans = max(ans, a);
        }
        cout << ans << endl;
    }
}