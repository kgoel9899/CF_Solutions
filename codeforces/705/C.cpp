#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
#define setpres cout << fixed << setprecision(10)
#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e18;
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--) {
        int n, q;
        cin >> n >> q;
        int ti = 1;
        vector<vector<int>> adj(n + 1);
        set<int> s;
        while(q--) {
            int type, x;
            cin >> type >> x;
            if(type == 1) {
                adj[x].push_back(ti);
                s.insert(ti);
                ti++;
            } else if(type == 2) {
                for(auto i : adj[x]) {
                    if(s.count(i) > 0) s.erase(i);
                }
                adj[x].clear();
            } else {
                while(s.size() && *s.begin() <= x) {
                    s.erase(s.begin());
                }
            }
            cout << s.size() << endl;
        }        
    }
}