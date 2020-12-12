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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        map<char, int> m;
        for(auto i : s) {
            m[i]++;
        }
        vector<int> ans(n, 1);
        for(int i=0;i<26;i++) {
            char c = 'a' + i;
            for(int j=0;j<n&&k>0;j++) {
                if(s[j] == c) {
                    ans[j] = 0;
                    k--;
                }
            }
        }
        string ss = "";
        for(int i=0;i<n;i++) {
            if(ans[i] == 1) ss += s[i];
        }
        cout << ss << endl;
    }
}