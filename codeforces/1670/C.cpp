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

// similar to editorial
int n;
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
int modRecursive(int a, int b, int c) {
    if(a == 1) return 1;
    if(b == 0) return 1;
    if(b == 1) return a;
    int temp = modRecursive(a, b / 2, c);
    if(b % 2 == 0) return (temp * temp) % c;
    else return (a * ((temp * temp) % c)) % c;
}
int32_t main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--) {
        cin >> n;
        par.clear();
        par.resize(n + 1);
        sz.clear();
        sz.resize(n + 1);
        vector<int> a(n + 1), b(n + 1), c(n + 1);
        for(int i=1;i<=n;i++) {
            cin >> a[i];
        }
        for(int i=1;i<=n;i++) {
            cin >> b[i];
        }
        for(int i=1;i<=n;i++) {
            cin >> c[i];
        }
        for(int i=1;i<=n;i++) {
            make_set(i);
        }
        for(int i=1;i<=n;i++) {
            union_sets(a[i], b[i]);
        }
        set<int> s;
        for(int i=1;i<=n;i++) {
            int p = find_set(a[i]);
            s.insert(p);
        }
        for(int i=1;i<=n;i++) {
            if(c[i]) {
                int p = find_set(a[i]);
                if(s.find(p) != s.end()) s.erase(p);
            } else if(a[i] == b[i]) {
                int p = find_set(a[i]);
                if(s.find(p) != s.end()) s.erase(p);
            }
        }
        // dbg(s);
        cout << modRecursive(2, s.size(), MOD) << endl;
    }
}