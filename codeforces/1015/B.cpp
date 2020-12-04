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
        string s, t;
        cin >> s >> t;
        map<int, int> a, b;
        for(auto i : s) {
            a[i]++;
        }
        for(auto i : t) {
            b[i]++;
        }
        if(a != b) cout << -1 << endl;
        else {
            vector<int> ans;
            for(int i=0;i<n;i++) {
                if(s[i] == t[i]) continue;
                int j = i + 1;
                for(;j<n;j++) {
                    if(s[j] == t[i]) break;
                }
                for(int k=j-1;k>=i;k--) {
                    swap(s[k], s[k + 1]);
                    ans.push_back(k + 1);
                }
            }
            cout << ans.size() << endl;
            for(auto i : ans) {
                cout << i << " ";
            }
            cout << endl;
        }
    }
}