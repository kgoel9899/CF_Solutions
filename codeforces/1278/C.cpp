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
        int n;
        cin >> n;
        vector<int> v(2 * n);
        for(int i=0;i<2*n;i++) {
            cin >> v[i];
        }
        vector<vector<int>> pref(n, vector<int>(2));
        if(v[0] == 1) pref[0][0] = 1;
        else pref[0][1] = 1;
        for(int i=1;i<n;i++) {
            pref[i][0] = pref[i - 1][0];
            pref[i][1] = pref[i - 1][1];
            if(v[i] == 1) pref[i][0]++;
            else pref[i][1]++;
        }
        vector<vector<int>> suff(n, vector<int>(2));
        if(v[2 * n - 1] == 1) suff[n - 1][0] = 1;
        else suff[n - 1][1] = 1;
        for(int i=2*n-2;i>=n;i--) {
            suff[i - n][0] = suff[i + 1 - n][0];
            suff[i - n][1] = suff[i + 1 - n][1];
            if(v[i] == 1) suff[i - n][0]++;
            else suff[i - n][1]++;
        }
        if(pref[n - 1][0] + suff[0][0] == pref[n - 1][1] + suff[0][1]) {
            cout << 0 << endl;
            continue;
        }
        // l1 + r1 = l2 + r2
        // l1 - l2 = r2 - r1
        map<int, int> m;
        m[0] = 0;
        for(int i=1;i<=n;i++) {
            int diff = pref[i - 1][0] - pref[i - 1][1];
            m[diff] = i;
        }
        int ans = n + n - m[0];
        for(int i=n-1;i<2*n-1;i++) {
            int diff = suff[i + 1 - n][1] - suff[i + 1 - n][0];
            if(m.find(diff) != m.end()) ans = min(ans, n - m[diff] + i + 1 - n);
        }
        cout << ans << endl;
    }
}