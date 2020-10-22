#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int N = 2e5 + 10;
vector<vector<int>> adj(N);
vector<int> col(N, -1);
int flag = 0;
void dfs(int curr, int cl) {
    col[curr] = cl;
    for(auto i : adj[curr]) {
        if(col[i] == col[curr]) {
            flag = 1;
            continue;
        }
        if(col[i] == -1) dfs(i, cl ^ 1);
    }
}
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> tot;
        for(int i=0;i<m;i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
            tot.push_back({a, b});
        }
        dfs(1, 0);
        if(flag == 1) cout << "NO" << endl;
        else {
            cout << "YES" << endl;
            for(auto i : tot) {
                int a = i.first, b = i.second;
                if(col[a] == 0) cout << 1;
                else cout << 0;
            }
            cout << endl;
        }
    }
}