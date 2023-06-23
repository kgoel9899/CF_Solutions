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
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> adj(n + 1);
        for(int i=0;i<m;i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        set<vector<int>> s;
        for(int i=0;i<k;i++) {
            int a, b, c;
            cin >> a >> b >> c;
            s.insert({a, b, c});
        }
        map<pair<int, int>, pair<int, int>> mp;
        queue<vector<int>> q; // {prev, curr, dist}
        q.push({0, 1, 0});
        set<pair<int, int>> vis;
        vis.insert({0, 1}); // {prev, curr}
        int ok = 0;
        while(!q.empty()) {
            auto f = q.front();
            int prev = f[0];
            int curr = f[1];
            int dist = f[2];
            q.pop();
            if(curr == n) {
                cout << dist << endl;
                vector<int> ans;
                pair<int, int> temp = {prev, curr};
                while(true) {
                    ans.push_back(temp.second);
                    if(mp.find(temp) == mp.end()) break;
                    temp = mp[temp];
                }
                reverse(all(ans));
                for(auto& j : ans) {
                    cout << j << " ";
                }
                cout << endl;
                ok = 1;
                break;
            }
            for(auto& i : adj[curr]) {
                if(vis.find({curr, i}) == vis.end() && s.find({prev, curr, i}) == s.end()) {
                    q.push({curr, i, dist + 1});
                    vis.insert({curr, i});
                    mp[{curr, i}] = {prev, curr};
                }
            }
        }
        if(!ok) cout << -1 << endl;
    }
} 