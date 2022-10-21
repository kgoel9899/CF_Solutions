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

#ifdef DEBUG
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }

int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        int n, k, d;
        cin >> n >> k >> d;
        queue<int> q;
        vector<int> vis(n + 1), par(n + 1, -1);
        for(int i=0;i<k;i++) {
            int x;
            cin >> x;
            if(vis[x]) continue;
            q.push(x);
            vis[x] = 1;
        }
        vector<vector<int>> adj(n + 1);
        map<pair<int, int>, int> m;
        for(int i=0;i<n-1;i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
            m[{min(a, b), max(a, b)}] = i + 1;
        }
        set<int> ans;
        while(!q.empty()) {
            auto f = q.front();
            q.pop();
            for(auto i : adj[f]) {
                if(i == par[f]) continue;
                if(vis[i]) {
                    // break
                    dbg(i, f);
                    ans.insert(m[{min(f, i), max(f, i)}]);
                    continue;
                }
                vis[i] = 1;
                q.push(i);
                par[i] = f;
            }
        }
        cout << ans.size() << endl;
        for(auto& i : ans) {
            cout << i << " ";
        }
        cout << endl;
    }
}