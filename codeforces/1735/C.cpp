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

vector<int> par, sz;
void make_set(int u) {
    par[u] = u;
    sz[u] = 1;
}
int find_set(int u) {
    if(par[u] == u) return u;
    return par[u] = find_set(par[u]);
}
void union_sets(int u, int v) {
    u = find_set(u);
    v = find_set(v);
    if(u == v) return;
    if(sz[u] < sz[v]) swap(u, v);
    par[v] = u;
    sz[u] += sz[v];
}
int32_t main() {
    fast;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        par.clear();
        par.resize(26);
        sz.clear();
        sz.resize(26);
        for(int i=0;i<26;i++) {
            make_set(i);
        }
        vector<vector<int>> adj(26, vector<int>(26));
        string ans = "";
        vector<int> in(26), out(26);
        int total = 0;
        for(int i=0;i<n;i++) {
            char c = s[i];
            int cc = s[i] - 'a';
            int found = 0;
            for(int j=0;j<26;j++) {
                if(adj[j][cc]) {
                    ans += ('a' + j);
                    found = 1;
                    break;
                }
            }
            if(!found) {
                assert(in[cc] == 0);
                char next = 'A';
                for(int j=0;j<26;j++) { 
                    if(j == cc) continue;
                    if(out[j] == 0 && (find_set(j) != find_set(cc) || total == 25)) {
                        next = char('a' + j);
                        break;
                    }
                }

                int nnext = next - 'a';
                adj[nnext][cc] = 1;
                out[nnext]++;
                in[cc]++;
                total++;
                union_sets(nnext, cc);
                ans += next;
            }
        }
        cout << ans << endl;
    }
}