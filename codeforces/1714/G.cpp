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
vector<vector<vector<int>>> adj;
vector<int> a, b, ans, path;
void dfs(int curr) {
    for(auto i : adj[curr]) {
        a[i[0]] = a[curr] + i[1];
        b[i[0]] = b[curr] + i[2];
        dfs(i[0]);
    }
}
void dfs2(int curr) {
    path.push_back(curr);
    int beg = 0, end = (int)path.size() - 1;
    int val = a[curr];
    while(beg <= end) {
        int mid = (beg + end) / 2;
        if(b[path[mid]] <= val) {
            ans[curr] = mid;
            beg = mid + 1;
        } else end = mid - 1;
    }
    for(auto i : adj[curr]) {
        dfs2(i[0]);
    }
    path.pop_back();
}
int32_t main() {
    fast;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        cin >> n;
        adj.clear();
        adj.resize(n + 1);
        for(int i=2;i<=n;i++) {
            int p, aa, bb;
            cin >> p >> aa >> bb;
            adj[p].push_back({i, aa, bb});
        }
        // dbg(adj);
        a.clear();
        a.resize(n + 1);
        b.clear();
        b.resize(n + 1);
        dfs(1);
        // dbg(a);
        // dbg(b);
        ans.clear();
        ans.resize(n + 1);
        path.clear();
        dfs2(1);
        for(int i=2;i<=n;i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}