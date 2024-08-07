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
    cin >> tt;
    while(tt--) {
        int n, k;
        cin >> n >> k;
        vector<set<int>> adj(n + 1);
        vector<int> in(n + 1);
        for(int i=0;i<k;i++) {
            vector<int> v(n);
            for(int j=0;j<n;j++) {
                cin >> v[j];
            }
            for(int j=2;j<n;j++) {
                if(adj[v[j - 1]].find(v[j]) == adj[v[j - 1]].end()) {
                    adj[v[j - 1]].insert(v[j]);
                    in[v[j]]++;
                }
            }
        }
        queue<int> q;
        for(int i=1;i<=n;i++) {
            if(!in[i]) {
                // dbg(i);
                q.push(i);
            }
        }
        // dbg(adj);
        // dbg(in);
        int tot = 0;
        while(!q.empty()) {
            auto f = q.front();
            q.pop();
            tot++;
            for(auto& i : adj[f]) {
                if(--in[i] == 0) q.push(i);
            }
        }
        if(tot == n) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}