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
        vector<vector<int>> adj(n + 1);
        for(int i=0;i<n-1;i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int ct = 0, start = 0;
        vector<int> leaf;
        for(int i=1;i<=n;i++) {
            if(adj[i].size() >= 3) {
                ct++;
                start = i;
            }
            if(adj[i].size() == 1) leaf.push_back(i);
        }
        if(ct > 1) {
            cout << "No" << endl;
            continue;
        }
        cout << "Yes" << endl;
        dbg(leaf);
        if(ct == 1) {
            cout << leaf.size() << endl;
            for(auto i : leaf) {
                cout << start << " " << i << endl;
            }
            cout << endl;
        } else {
            assert(leaf.size() == 2);
            cout << 1 << endl;
            cout << leaf[0] << " " << leaf[1] << endl;
        }
    }
}