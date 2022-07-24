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
        vector<string> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        vector<vector<int>> adj(26);
        vector<int> indeg(26);
        int ok = 1;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                int x = v[i].size(), y = v[j].size();
                int a = 0, b = 0;
                while(a < x && b < y && v[i][a] == v[j][b]) {
                    a++;
                    b++;
                }
                if(a == x || b == y) {
                    if(x > y) {
                        ok = 0;
                        break;
                    }
                } else {
                    adj[v[i][a] - 'a'].push_back(v[j][b] - 'a');
                    indeg[v[j][b] - 'a']++;
                }
            }
        }
        if(!ok) {
            cout << "Impossible" << endl;
            continue;
        }
        queue<int> q;
        for(int i=0;i<26;i++) {
            if(indeg[i] == 0) q.push(i);
        }
        string ans = "";
        while(!q.empty()) {
            auto f = q.front();
            q.pop();
            ans += 'a' + f;
            for(auto i : adj[f]) {
                if(--indeg[i] == 0) q.push(i);
            }
        }
        if(ans.size() != 26) {
            cout << "Impossible" << endl;
            continue;
        }
        cout << ans << endl;
    }
}