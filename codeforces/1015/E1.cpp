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
        int n, m;
        cin >> n >> m;
        vector<string> v(n);
        vector<vector<int>> vis(n, vector<int>(m));
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        // for(auto i : v) {
        //     cout << i << endl;
        // }
        // return 0;
        vector<vector<int>> ans;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(v[i][j] == '*') {
                    // cout << "here" << endl;
                    int up = 0, down = 0, left = 0, right = 0;
                    for(int a=i+1;a<n;a++) {
                        if(v[a][j] == '.') break;
                        else down++;
                    }
                    for(int a=i-1;a>=0;a--) {
                        if(v[a][j] == '.') break;
                        else up++;
                    }
                    for(int a=j+1;a<m;a++) {
                        if(v[i][a] == '.') break;
                        else right++;
                    }
                    for(int a=j-1;a>=0;a--) {
                        if(v[i][a] == '.') break;
                        else left++;
                    }
                    int mn = min({up, down, left, right});
                    if(mn == 0) continue;
                    ans.push_back({i, j, mn});
                    for(int a=i+1;a<i+1+mn;a++) {
                        vis[a][j] = 1;
                    }
                    for(int a=i-1;a>i-1-mn;a--) {
                        vis[a][j] = 1;
                    }
                    for(int a=j+1;a<j+1+mn;a++) {
                        vis[i][a] = 1;
                    }
                    for(int a=j-1;a>j-1-mn;a--) {
                        vis[i][a] = 1;
                    }
                    vis[i][j] = 1;
                }
            }
        }
        // for(auto i : vis) {
        //     for(auto j : i) {
        //         cout << j << " ";
        //     }
        //     cout << endl;
        // }
        // return 0;
        int flag = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(v[i][j] == '*' && vis[i][j] == 0) {
                    flag = 1;
                    break;
                } 
            }
        }
        if(flag == 1) cout << -1 << endl;
        else {
            cout << ans.size() << endl;
            for(auto i : ans) {
                cout << i[0] + 1 << " " << i[1] + 1 << " " << i[2] << endl;
            }
        }
    }
}