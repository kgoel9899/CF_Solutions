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
        int a, b;
        cin >> a >> b;
        string s;
        cin >> s;
        while(s.size() && s.back() == '0') {
            s.pop_back();
        }
        reverse(s.begin(), s.end());
        while(s.size() && s.back() == '0') {
            s.pop_back();
        }
        reverse(s.begin(), s.end());
        int n = s.size();
        if(n == 0) cout << 0 << endl;
        else {
            int ans = 0;
            int i = 0;
            for(;i<n;i++) {
                if(s[i] == '1') continue;
                int ct = 0;
                while(i < n && s[i] == '0') {
                    ct++;
                    i++;
                }
                ans += min(a, b * ct);
            }
            cout << ans + a << endl;
        }
    }
}