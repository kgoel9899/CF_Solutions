#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int N = 2e5 + 5;
vector<vector<int>> adj(N);
vector<int> dist(N), pa(N);
int n;
void dfs(int curr, int par, int di) {
    dist[curr] = di;
    pa[curr] = par;
    for(auto i : adj[curr]) {
        if(i == par) continue;
        dfs(i, curr, di + 1);
    }
}
int32_t main() {
    int t = 1;
    // cin >> t;
    while(t--) {
        cin >> n;
        for(int i=0;i<n-1;i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(1, 0, 0);
        set<pair<int, int>> s;
        for(int i=1;i<=n;i++) {
            if(dist[i] >= 3) s.insert({-dist[i], i});
        }
        int ans = 0;
        while(!s.empty()) {
            int nw = pa[s.begin()->second];
            ans++;
            if(s.find(make_pair(-dist[nw], nw)) != s.end()) s.erase(s.find(make_pair(-dist[nw], nw)));
            for(auto i : adj[nw]) {
                if(s.find(make_pair(-dist[i], i)) != s.end()) s.erase(s.find(make_pair(-dist[i], i)));
            }
        }
        cout << ans << endl;
    }
    return 0;
}