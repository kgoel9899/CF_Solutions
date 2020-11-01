#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e18;
int32_t main() {
    int t = 1;
    // cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int n = s.size(), tens = 1, suff = 0;
        int ans = 0;
        for(int i=n-1;i>=0;i--) {
            int temp = (i * (i + 1)) / 2;
            temp %= MOD;
            temp *= (s[i] - '0');
            temp %= MOD;
            temp *= tens;
            temp %= MOD;
            ans += temp;
            ans %= MOD;
            ans += suff * (s[i] - '0');
            ans %= MOD;
            suff += tens * (n - i);
            suff %= MOD;
            tens *= 10;
            tens %= MOD;
        }
        cout << ans % MOD << endl;
    }
}