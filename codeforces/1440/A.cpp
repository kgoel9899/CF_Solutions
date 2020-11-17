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
    cin >> t;
    while(t--) {
        int n, c0, c1, h;
        cin >> n >> c0 >> c1 >> h;
        string s;
        cin >> s;
        int ze = 0, one = 0, ans = 0;
        for(int i=0;i<n;i++) {
            if(s[i] == '0') {
                ze++;
                ans += c0;
            } else {
                one++;
                ans += c1;
            }
        }
        if(-c1 + h + c0 < 0) cout << n * c0 + h * one << endl;
        else if(-c0 + h + c1 < 0) cout << n * c1 + h * ze << endl;
        else cout << ans << endl;
    }
}