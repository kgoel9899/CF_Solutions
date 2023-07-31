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
        vector<int> v(n + 1);
        for(int i=1;i<=n;i++) {
            cin >> v[i];
        }
        vector<int> have(n + 1);
        for(int i=0;i<k;i++) {
            int x;
            cin >> x;
            have[x] = 1;
        }
        vector<vector<int>> adj(n + 1);
        vector<int> in(n + 1);
        vector<int> cost(n + 1);
        for(int i=1;i<=n;i++) {
            int m;
            cin >> m;
            if(m == 0 && !have[i]) cost[i] = v[i];
            while(m--) {
                int x;
                cin >> x;
                adj[x].push_back(i);
                in[i]++;
            }
        }
        queue<int> q;
        for(int i=1;i<=n;i++) {
            if(in[i] == 0) q.push(i);
        }
        dbg(adj);
        dbg(in);
        dbg(cost);
        while(!q.empty()) {
            auto f = q.front();
            q.pop();
            dbg(f);
            for(auto& i : adj[f]) {
                cost[i] += min(v[f], cost[f]);
                if(--in[i] == 0) {
                    if(have[i]) cost[i] = 0;
                    q.push(i);
                }
            }
            dbg(cost);
        }
        for(int i=1;i<=n;i++) {
            cout << min(v[i], cost[i]) << " ";
        }
        cout << endl;
    }
}