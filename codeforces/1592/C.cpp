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

int n, k, xr, node1, ok;
vector<int> v, sub, pars;
vector<vector<int>> adj;
void dfs(int curr, int par) {
    sub[curr] = v[curr];
    for(auto i : adj[curr]) {
        if(i == par) continue;
        dfs(i, curr);
        sub[curr] ^= sub[i];
    }
    if(node1 == -1 && sub[curr] == xr) {
        node1 = curr;
        pars.push_back(par);
        return;
    }
    if(node1 != -1) {
        if(pars.back() == curr) {
            if(sub[curr] == 0) ok = 1;
            pars.push_back(par);
        } else {
            if(sub[curr] == xr) ok = 1;
        }
    }
}
int32_t main() {
    fast;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        cin >> n >> k;
        xr = 0;
        v.clear();
        v.resize(n + 1);
        adj.clear();
        adj.resize(n + 1);
        for(int i=1;i<=n;i++) {
            cin >> v[i];
            xr ^= v[i];
        }
        for(int i=0;i<n-1;i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        if(xr == 0) {
            cout << "YES" << endl;
            continue;
        }
        if(k == 2) {
            cout << "NO" << endl;
            continue;
        }
        sub.clear();
        sub.resize(n + 1);
        pars.clear();
        node1 = -1;
        ok = 0;
        dfs(1, 0);
        if(ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}