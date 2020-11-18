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
        int m, n;
        cin >> m >> n;
        vector<vector<int>> ans(m, vector<int>(n, 1));
        vector<vector<int>> v(m, vector<int>(n));
        set<int> row, col;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                cin >> v[i][j];
                if(v[i][j] == 0) {
                    row.insert(i);
                    col.insert(j);
                } 
            }
        }
        for(auto i : row) {
            for(int j=0;j<n;j++) {
                ans[i][j] = 0;
            }
        }
        for(auto j : col) {
            for(int i=0;i<m;i++) {
                ans[i][j] = 0;
            }
        }
        row.clear();
        col.clear();
        vector<vector<int>> temp = ans;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(ans[i][j] == 1) {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        for(auto i : row) {
            for(int j=0;j<n;j++) {
                temp[i][j] = 1;
            }
        }
        for(auto j : col) {
            for(int i=0;i<m;i++) {
                temp[i][j] = 1;
            }
        }
        if(temp == v) {
            cout << "YES" << endl;
            for(int i=0;i<m;i++) {
                for(int j=0;j<n;j++) {
                    cout << ans[i][j] << " ";
                }
                cout << endl;
            }
        } else cout << "NO" << endl;
    }
}