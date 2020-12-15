#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e18;
// string ans = "";
// int helper(int x, int curr) {
//     cout << x << endl;
//     if(x < 0) return 0;
//     if(x == 0) return 1;
//     for(int i=curr;i<=9;i++) {
//         ans += to_string(i);
//         int temp = helper(x - i, i + 1);
//         if(temp == 1) return 1;
//         ans.pop_back();
//     }
//     return 0;
// }
int32_t main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--) {
        int x;
        cin >> x;
        string ans = "";
        if(x > 45) cout << -1 << endl;
        else {
            int curr = 9;
            while(x >= curr && curr > 1) {
                ans += to_string(curr);
                x -= curr;
                curr--;
                // cout << curr << endl;
            }
            if(x != 0) ans += to_string(x);
            reverse(ans.begin(), ans.end());
            cout << ans << endl;
        }
    }
}