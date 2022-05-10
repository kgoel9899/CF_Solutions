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
string s;
struct Node {
    int w, b;
    Node() {
        w = 0;
        b = 0;
    }
};
int fin;
Node dfs(int curr) {
    Node ans;
    for(auto i : adj[curr]) {
        Node temp = dfs(i);
        ans.w += temp.w;
        ans.b += temp.b;
    }
    if(s[curr] == 'W') ans.w++;
    else ans.b++;
    if(ans.b == ans.w) fin++;
    return ans;
}
int32_t main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--) {
        fin = 0;
        cin >> n;
        adj.clear();
        adj.resize(n + 1);
        vector<int> v(n - 1);
        for(int i=0;i<n-1;i++) {
            cin >> v[i];
        }
        for(int i=0;i<n-1;i++) {
            adj[v[i]].push_back(i + 2);
        }
        cin >> s;
        s = '#' + s;
        dbg(adj);
        dfs(1);
        cout << fin << endl;
    }
}