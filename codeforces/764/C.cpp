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

bool dfs(int curr, int par, int col, vector<int>& v, vector<vector<int>>& adj) {
    if(v[curr] != col) return false;
    for(auto i : adj[curr]) {
        if(i == par) continue;
        if(!dfs(i, curr, col, v, adj)) return false;
    }
    return true;
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        vector<vector<int>> adj(n + 1);
        for(int i=0;i<n-1;i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<int> v(n + 1);
        for(int i=1;i<=n;i++) {
            cin >> v[i];
        }
        int posx = -1, posy = -1;
        for(int i=1;i<=n;i++) {
            for(auto j : adj[i]) {
                if(v[i] != v[j]) {
                    posx = i;
                    posy = j;
                    break;
                }
            }
            if(posx != -1) break;
        }
        if(posx == -1) {
            cout << "YES" << endl;
            cout << 1 << endl;
            continue;
        }
        dbg(posx);
        bool ans = true;
        for(auto i : adj[posx]) {
            ans &= dfs(i, posx, v[i], v, adj);
        }
        if(ans) {
            cout << "YES" << endl;
            cout << posx << endl;
        } else {
            ans = true;
            for(auto i : adj[posy]) {
                ans &= dfs(i, posy, v[i], v, adj);
            }
            if(ans) {
                cout << "YES" << endl;
                cout << posy << endl;
            } else cout << "NO" << endl;
        }
    }
}