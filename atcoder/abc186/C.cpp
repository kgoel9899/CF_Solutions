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
        int ans = 0;
        for(int i=1;i<=n;i++) {
            string s = to_string(i);
            int flag = 0;
            for(auto j : s) {
                if(j == '7') {
                    flag = 1;
                    break;
                }
            }
            if(flag == 1) continue;
            s = "";
            int temp = i;
            while(temp) {
                s += to_string(temp % 8);
                temp /= 8;
            }
            reverse(s.begin(), s.end());
            for(auto j : s) {
                if(j == '7') {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) ans++;
        }
        cout << ans << endl;
    }
}