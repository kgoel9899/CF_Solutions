#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
#define MOD 1000000007
#define int long long
#define ld long double
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
int32_t main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<string> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        char a = v[0][1], b = v[1][0];
        char c = v[n - 1][n - 2], d = v[n - 2][n - 1];
        vector<pair<int, int>> ans;
        if(a == b) {
            if(a == '0') {
                if(c == '0') ans.push_back({n - 1, n - 2});
                if(d == '0') ans.push_back({n - 2, n - 1});
            } else {
                if(c == '1') ans.push_back({n - 1, n - 2});
                if(d == '1') ans.push_back({n - 2, n - 1});
            }
        } else if(c == d) {
            if(c == '0') {
                if(a == '0') ans.push_back({0, 1});
                if(b == '0') ans.push_back({1, 0});
            } else {
                if(a == '1') ans.push_back({0, 1});
                if(b == '1') ans.push_back({1, 0});   
            }
        } else {
            ans.push_back({1, 0});
            if(a == '1') {
                if(c == '1') ans.push_back({n - 1, n - 2});
                else ans.push_back({n - 2, n - 1});
            } else {
                if(c == '0') ans.push_back({n - 1, n - 2});
                else ans.push_back({n - 2, n - 1});
            }
        }
        cout << ans.size() << endl;
        for(auto i : ans) {
            cout << i.first + 1 << " " << i.second + 1 << endl;
        }
    }
}