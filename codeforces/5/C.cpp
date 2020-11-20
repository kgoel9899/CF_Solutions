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
        string s;
        cin >> s;
        int n = s.size();
        s = '#' + s;
        vector<int> c(n + 1, -1), d(n + 1, -1);
        stack<int> st;
        int ans = 0, ct = 0;
        for(int i=1;i<=n;i++) {
            if(s[i] == '(') st.push(i);
            else {
                if(!st.empty()) {
                    int t = st.top();
                    st.pop();
                    c[i] = t;
                    d[i] = t;
                    if(s[d[i] - 1] == ')' && c[d[i] - 1] != -1) c[i] = c[d[i] - 1];
                    ans = max(ans, i - c[i] + 1);
                }
            }
        }
        for(int i=1;i<=n;i++) {
            if(s[i] == ')' && c[i] != -1 && i - c[i] + 1 == ans) ct++;
        }
        if(ans == 0) ct = 1;
        cout << ans << " " << ct << endl;
    }
}