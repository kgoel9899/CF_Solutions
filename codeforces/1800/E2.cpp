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
    sz[u] += sz[v];
    par[v] = u;
}
int32_t main() {
    fast;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        int n, k;
        cin >> n >> k;
        par.clear();
        par.resize(n);
        sz.clear();
        sz.resize(n);
        for(int i=0;i<n;i++) {
            make_set(i);
        }
        string s, t;
        cin >> s >> t;
        for(int i=0;i<n;i++) {
            if(i + k < n) union_sets(i, i + k);
            if(i + k + 1 < n) union_sets(i, i + k + 1);
        }
        // for(int i=0;i<n;i++) {
        //     dbg(i, find_set(i));
        // }
        map<int, map<char, int>> m1, m2;
        for(int i=0;i<n;i++) {
            m1[find_set(i)][s[i]]++;
        }
        for(int i=0;i<n;i++) {
            m2[find_set(i)][t[i]]++;
        }
        if(m1 == m2) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}