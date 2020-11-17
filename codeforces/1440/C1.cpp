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
        int n, m;
        cin >> n >> m;
        vector<string> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        vector<vector<int>> ans;
        for(int i=0;i<n-1;i++) {
            for(int j=0;j<m-1;j++) {
                if(v[i][j] == '1') {
                    ans.push_back({i + 1, j, i, j, i, j + 1});
                    ans.push_back({i, j, i + 1, j, i + 1, j + 1});
                    ans.push_back({i, j, i, j + 1, i + 1, j + 1});
                }
            }
        }
        for(int i=0;i<n-1;i++) {
            if(v[i][m - 1] == '1') {
                int j = m - 1;
                ans.push_back({i, j, i + 1, j, i, j - 1});
                ans.push_back({i, j, i + 1, j, i + 1, j - 1});
                ans.push_back({i, j, i, j - 1, i + 1, j - 1});
            }
        }
        for(int j=0;j<m-1;j++) {
            if(v[n - 1][j] == '1') {
                int i = n - 1;
                ans.push_back({i, j, i, j + 1, i - 1, j + 1});
                ans.push_back({i, j, i, j + 1, i - 1, j});
                ans.push_back({i, j, i - 1, j, i - 1, j + 1});
            }
        }
        if(v[n - 1][m - 1] == '1') {
            int i = n - 1, j = m - 1;
            ans.push_back({i, j, i, j - 1, i - 1, j - 1});
            ans.push_back({i, j, i, j - 1, i - 1, j});
            ans.push_back({i, j, i - 1, j, i - 1, j - 1});
        }
        cout << ans.size() << endl;
        for(auto i : ans) {
            for(auto j : i) {
                cout << j + 1 << " ";
            }
            cout << endl;
        }
    }
}