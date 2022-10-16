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
        vector<set<int>> adj(26);
        vector<int> in(26);
        set<int> used;
        for(int i=0;i<n;i++) {
            cin >> v[i];
            used.insert(v[i][0] - 'a');
            for(int j=1;j<v[i].size();j++) {
                int x = v[i][j - 1] - 'a';
                int y = v[i][j] - 'a';
                if(adj[x].find(y) == adj[x].end()) {
                    adj[x].insert(y);
                    in[y]++;
                }
                used.insert(x);
                used.insert(y);
            }
        }
        dbg(adj);
        dbg(in);
        string ans = "";
        set<int> done;
        for(int i=0;i<26;i++) {
            if(used.find(i) != used.end() && in[i] == 0 && done.find(i) == done.end()) {
                queue<int> q;
                q.push(i);
                dbg(i);
                while(!q.empty()) {
                    auto f = q.front();
                    q.pop();
                    done.insert(f);
                    ans += char('a' + f);
                    for(auto& j : adj[f]) {
                        in[j]--;
                        if(in[j] == 0) q.push(j);
                    }
                }
            }
        }
        cout << ans << endl;
    }
}