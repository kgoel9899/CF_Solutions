#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
string helper(string s, string ref) {
    for(int i=0;i<s.size();i++) {
        if(i % 3 == 0) s[i] = ref[0];
        else if((i - 1) % 3 == 0) s[i] = ref[1];
        else s[i] = ref[2];
    }
    return s;
}
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> r(3), g(3), b(3);
        for(int i=0;i<3;i++) {
            for(int j=i;j<n;j++) {
                if((j - i) % 3 == 0) {
                    if(s[j] != 'R') r[i]++;
                    if(s[j] != 'G') g[i]++;
                    if(s[j] != 'B') b[i]++;
                }
            }
        }
        int a = r[0] + g[1] + b[2];
        int bb = r[0] + b[1] + g[2];
        int c = g[0] + b[1] + r[2];
        int d = g[0] + r[1] + b[2];
        int e = b[0] + g[1] + r[2];
        int f = b[0] + r[1] + g[2];
        int ans = min({a, bb, c, d, e, f});
        cout << ans << endl;
        if(ans == a) cout << helper(s, "RGB") << endl;
        else if(ans == bb) cout << helper(s, "RBG") << endl;
        else if(ans == c) cout << helper(s, "GBR") << endl;
        else if(ans == d) cout << helper(s, "GRB") << endl;
        else if(ans == e) cout << helper(s, "BGR") << endl;
        else cout << helper(s, "BRG") << endl;
    }
}