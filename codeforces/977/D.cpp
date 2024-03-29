#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e18;
int32_t main() {
    int t = 1;
    // cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        vector<vector<int>> adj(n);
        vector<int> indeg(n);
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(i == j) continue;
                if(v[i] == 3 * v[j] || 2 * v[i] == v[j]) {
                    adj[i].push_back(j);
                    indeg[j]++;
                }
            }
        }
        // for(int i=0;i<n;i++) {
        //     cout << v[i] << ": ";
        //     for(auto j : adj[i]) {
        //         cout << v[j] << " ";
        //     }
        //     cout << endl;
        // }
        queue<int> q;
        for(int i=0;i<n;i++) {
            if(indeg[i] == 0) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()) {
            int f = q.front();
            // cout << f << " ";
            q.pop();
            ans.push_back(v[f]);
            for(auto i : adj[f]) {
                // indeg[i]--;
                if(--indeg[i] == 0) q.push(i);
            }
            // for(int i=0;i<adj[f].size();i++) {
            //     indeg[adj[f][i]]--;
            //     if(indeg[adj[f][i]] == 0) q.push(adj[f][i]);
            // }
        }
        // cout << endl;
        // cout << ans.size() << endl;
        for(auto i : ans) {
            cout << i << " ";
        }
        cout << endl;
    }
}