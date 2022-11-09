#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
#define setpres cout << fixed << setprecision(10)
#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e3;

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
        string s, t;
        cin >> s >> t;
        int n;
        cin >> n;
        vector<vector<int>> v(26, vector<int>(26, INF));
        for(int i=0;i<26;i++) {
            v[i][i] = 0;
        }
        for(int i=0;i<n;i++) {
            char x, y;
            cin >> x >> y;
            int w;
            cin >> w;
            v[x - 'a'][y - 'a'] = min(v[x - 'a'][y - 'a'], w);
        }
        if(s.size() != t.size()) {
            cout << -1 << endl;
            continue;
        }
        for(int k=0;k<26;k++) {
            for(int i=0;i<26;i++) {
                for(int j=0;j<26;j++) {
                    v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
                }
            }
        }
        int ans = 0, ok = 1;
        string fin = s;
        for(int i=0;i<s.size();i++) {
            if(s[i] != t[i]) {
                int curr = INF;
                for(int j=0;j<26;j++) {
                    int temp = v[s[i] - 'a'][j] + v[t[i] - 'a'][j];
                    if(temp < curr) {
                        fin[i] = char('a' + j);
                        curr = temp;
                    }
                }
                if(curr == INF) {
                    ok = 0;
                    break;
                }
                ans += curr;
            }
        }
        if(ok) {
            cout << ans << endl;
            cout << fin << endl;
        } else cout << -1 << endl;
    }
}