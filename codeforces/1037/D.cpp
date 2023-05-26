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
        vector<multiset<int>> adj(n + 1);
        for(int i=0;i<n-1;i++) {
            int a, b;
            cin >> a >> b;
            adj[a].insert(b);
            adj[b].insert(a);
        }
        dbg(adj);
        vector<int> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        if(v[0] != 1) {
            cout << "No" << endl;
            continue;
        }
        int ind = 1, ok = 1;
        queue<int> q;
        q.push(1);
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto f = q.front();
                q.pop();
                int tot = adj[f].size();
                for(int i=ind;i<ind+tot;i++) {
                    if(adj[f].find(v[i]) == adj[f].end()) {
                        ok = 0;
                        break;
                    }
                    q.push(v[i]);
                    adj[f].erase(adj[f].find(v[i]));
                    adj[v[i]].erase(adj[v[i]].find(f));
                }
                if(!ok) break;
                ind += tot;
            }
            if(!ok) break;
        }
        if(ok) cout << "Yes" << endl;
        else cout << "No" << endl;

    }
}