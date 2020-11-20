#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
// #define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
// const int INF = 1e18;
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        int a = 0, b = 0;
        for(auto i : s) {
            if(i == 'a') a++;
            else b++;
        }
        for(auto i : t) {
            if(i == 'a') a++;
            else b++;
        }
        if(a % 2 == 1 || b % 2 == 1) {
            cout << -1 << endl;
            continue;
        }
        vector<vector<int>> ans;
        vector<int> ab, ba;
        for(int i=0;i<n;i++) {
            if(s[i] == 'a' && t[i] == 'b') ab.push_back(i);
            if(s[i] == 'b' && t[i] == 'a') ba.push_back(i);
        }
        for(int i=1;i<ab.size();i+=2) {
            ans.push_back({ab[i], ab[i - 1]});
        }
        for(int i=1;i<ba.size();i+=2) {
            ans.push_back({ba[i], ba[i - 1]});
        }
        if(ab.size() % 2 == 1) {
            ans.push_back({ab[int(ab.size()) - 1], ab[int(ab.size() - 1)]});
            ans.push_back({ab[int(ab.size()) - 1], ba[int(ba.size()) - 1]});
        }
        cout << ans.size() << endl;
        for(auto i : ans) {
            cout << i[0] + 1 << " " << i[1] + 1 << endl;
        }
    }
}