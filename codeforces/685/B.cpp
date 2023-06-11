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

// set merging technique - CPH
int n, q;
vector<int> cent, sub;
vector<vector<int>> adj;
vector<set<pair<int, int>>> child; // {subtree size, node}
void dfs(int curr) {
    for(auto& i : adj[curr]) {
        dfs(i);
        sub[curr] += sub[i];
        if(child[i].size() > child[curr].size()) swap(child[i], child[curr]);
        for(auto& j : child[i]) child[curr].insert(j);
    }
    child[curr].insert({sub[curr], curr});
    cent[curr] = child[curr].lower_bound({(sub[curr] + 1) / 2, 0})->second;
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        cin >> n >> q;
        adj.clear();
        adj.resize(n + 1);
        for(int i=2;i<=n;i++) {
            int x;
            cin >> x;
            adj[x].push_back(i);
        }
        cent.clear();
        cent.resize(n + 1);
        sub.clear();
        sub.resize(n + 1, 1);
        child.clear();
        child.resize(n + 1);
        dfs(1);
        while(q--) {
            int x;
            cin >> x;
            cout << cent[x] << endl;
        }
    }
}