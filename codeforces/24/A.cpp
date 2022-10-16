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

int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        vector<vector<pair<int, int>>> adj(n + 1);
        int tot = 0;
        for(int i=0;i<n;i++) {
            int a, b, c;
            cin >> a >> b >> c;
            adj[a].push_back({b, -c});
            adj[b].push_back({a, c});
            tot += c;
        }
        dbg(adj);
        vector<int> vis(n + 1);
        int ans = 0;
        int curr = 1;
        while(true) {
            vis[curr] = 1;
            int ok = 0;
            for(auto i : adj[curr]) {
                if(vis[i.first]) continue;
                curr = i.first;
                if(i.second > 0) ans += i.second;
                ok = 1;
                break;
            }
            if(!ok) {
                if(adj[curr][0].first == 1 && adj[curr][0].second > 0) ans += adj[curr][0].second; 
                else if(adj[curr][1].first == 1 && adj[curr][1].second > 0) ans += adj[curr][1].second;
                break;
            }
        }
        cout << min(ans, tot - ans) << endl;
    }
}