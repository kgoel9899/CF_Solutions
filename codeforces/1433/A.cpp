#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
int32_t main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s = to_string(n);
        // vector<int> v(n);
        // for(int i=0;i<n;i++) {
        //     cin >> v[i];
        // }
        int ans = ((s[0] - '0') - 1) * 10;
        for(int i=1;i<=s.size();i++) {
            ans += i;
        }
        cout << ans << endl;
    }
}