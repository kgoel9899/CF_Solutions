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
    cin >> tt;
    while(tt--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> adj(n + 1);
        vector<int> level(n + 1), vis(n + 1), indeg(n + 1);
        for(int i=0;i<n-1;i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
            indeg[a]++;
            indeg[b]++;
        }
        queue<int> q;
        map<int, int> m;
        for(int i=1;i<=n;i++) {
            if(indeg[i] == 1) {
                q.push(i);
                level[i] = 1;
                m[level[i]]++;
                vis[i] = 1;
            }
        }
        while(!q.empty()) {
            int f = q.front();
            q.pop();
            for(auto i : adj[f]) {
                if(vis[i]) continue;
                indeg[i]--;
                if(indeg[i] == 1) {
                    vis[i] = 1;
                    level[i] = level[f] + 1;
                    q.push(i);
                    m[level[i]]++;
                }
            }
        }
        if(n == 1) n = 0;
        for(auto i : m) {
            n -= i.second;
            k--;
            if(k == 0) break;
        }
        cout << n << endl;
    }
}
// 1
// 6 2
// 2 5
// 4 3
// 6 2
// 1 5
// 4 5