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

int n, m, k, tin, st, endd;
vector<int> par, enter;
vector<vector<int>> adj;
bool dfs(int curr, int parent) {
    dbg(curr);
    par[curr] = parent;
    enter[curr] = tin;
    tin++;
    for(auto& i : adj[curr]) {
        if(i == parent) continue;
        if(par[i] == -1) {
            if(dfs(i, curr)) return true;
        } else {
            if(tin - enter[i] >= k + 1) {
                st = i;
                endd = curr;
                return true;
            }
        }
    }
    return false;
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        cin >> n >> m >> k;
        adj.clear();
        adj.resize(n + 1);
        for(int i=0;i<m;i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        par.clear();
        par.resize(n + 1, -1);
        enter.clear();
        enter.resize(n + 1);
        st = -1, endd = -1;
        for(int i=1;i<=n;i++) {
            if(par[i] == -1) {
                tin = 1;
                if(dfs(i, 0)) {
                    dbg("here");
                    break;
                }
            }
        }
        dbg(par);
        dbg(st, endd);
        vector<int> ans;
        int here = endd;
        while(here != st) {
            ans.push_back(here);
            here = par[here];
        }
        ans.push_back(st);
        dbg(ans);
        cout << ans.size() << endl;
        for(auto& i : ans) {
            cout << i << " ";
        }
        cout << endl;
    }
}