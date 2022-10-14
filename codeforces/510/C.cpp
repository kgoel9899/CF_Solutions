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
        vector<int> in(26);
        int ok = 1;
        for(int i=1;i<n;i++) {
            int l = 0, r = 0;
            while(l < v[i - 1].size() && r < v[i].size()) {
                if(v[i - 1][l] != v[i][r]) break;
                l++;
                r++;
            }
            if(l == v[i - 1].size() && r == v[i].size()) continue;
            if(r == v[i].size()) {
                ok = 0;
                break;
            }
            if(l == v[i - 1].size()) continue;
            adj[v[i - 1][l] - 'a'].push_back(v[i][r] - 'a');
            in[v[i][r] - 'a']++;
        }
        if(!ok) {
            cout << "Impossible" << endl;
            continue;
        }
        string ans = "";
        queue<int> q;
        for(int i=0;i<26;i++) {
            if(in[i] == 0) q.push(i);
        }
        while(!q.empty()) {
            auto f = q.front();
            q.pop();
            ans += char('a' + f);
            for(auto i : adj[f]) {
                in[i]--;
                if(in[i] == 0) q.push(i);
            }
        }
        if(ans.size() == 26) cout << ans << endl;
        else cout << "Impossible" << endl;
    }
}