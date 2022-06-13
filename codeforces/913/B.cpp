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

int n;
vector<vector<int>> adj;
vector<int> leaf;
int ans;
void dfs(int curr, int par) {
    dbg(curr);
    int ct = 0;
    for(auto i : adj[curr]) {
        if(i == par) continue;
        ct++;
        dfs(i, curr);
    }
    if(ct == 0) leaf[curr] = 1;
    else {
        ct = 0;
        for(auto i : adj[curr]) {
            if(i == par) continue;
            if(leaf[i]) ct++;
        }
        if(ct < 3) ans = ans & 0;
    }
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        cin >> n;
        adj.clear();
        adj.resize(n + 1);
        leaf.clear();
        leaf.resize(n + 1);
        for(int i=2;i<=n;i++) {
            int a;
            cin >> a;
            adj[a].push_back(i);
            adj[i].push_back(a);
        }
        dbg(adj);
        ans = 1;
        dfs(1, 0);
        dbg(leaf);
        if(ans) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}