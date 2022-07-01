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
        string s, t;
        cin >> s >> t;
        int n = s.size();
        vector<vector<int>> nxt(n, vector<int>(26, n));
        // nxt[i][j] = min index (from i to n) of the jth letter from i
        nxt[n - 1][s.back() - 'a'] = n - 1;
        for(int i=n-2;i>=0;i--) {
            for(int j=0;j<26;j++) {
                nxt[i][j] = nxt[i + 1][j];
            }
            nxt[i][s[i] - 'a'] = i;
        }
        map<char, int> m;
        for(auto i : s) {
            m[i]++;
        }
        // dbg(m);
        // dbg(nxt);
        int ok = 1;
        for(auto i : t) {
            if(m.find(i) == m.end()) {
                ok = 0;
                break;
            }
        }
        if(!ok) {
            cout << -1 << endl;
            continue;
        }
        // dbg(nxt);
        int ans = 0, curr = 0;
        for(auto i : t) {
            if(curr == n) {
                curr = 0;
                ans++;
            }
            // assert(curr < n);
            curr = nxt[curr][i - 'a'];
            if(curr == n) {
                ans++;
                curr = nxt[0][i - 'a'];
            }
            curr++;
            // dbg(i, curr);
            dbg(i, curr, ans);
        }
        ans++;
        cout << ans << endl;
    }
}