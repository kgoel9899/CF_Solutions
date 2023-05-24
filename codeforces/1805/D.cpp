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

// editorial idea
int n;
vector<vector<int>> adj;
void dfs(int curr, int par, vector<int>& dist) {
    for(auto& i : adj[curr]) {
        if(i == par) continue;
        dist[i] = 1 + dist[curr];
        dfs(i, curr, dist);
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
        for(int i=0;i<n-1;i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<int> dist1(n + 1);
        dfs(1, 0, dist1);
        int a = max_element(all(dist1)) - dist1.begin();
        dist1 = vector<int>(n + 1);
        dfs(a, 0, dist1);
        int b = max_element(all(dist1)) - dist1.begin();
        dbg(a, b);
        vector<int> dist2(n + 1);
        dfs(b, 0, dist2);
        vector<int> mx(n);
        for(int i=0;i<n;i++) {
            mx[i] = max(dist1[i + 1], dist2[i + 1]);
        }
        sort(all(mx));
        dbg(mx);
        int ans = 0;
        for(int i=1;i<=n;i++) {
            while(ans < n && mx[ans] < i) {
                ans++;
            }
            cout << min(n, ans + 1) << " ";
        }
        cout << endl;
    }
}