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
        int n, m;
        cin >> n >> m;
        vector<string> v(n);
        int tot = 0;
        for(int i=0;i<n;i++) {
            cin >> v[i];
            for(int j=0;j<m;j++) {
                if(v[i][j] == '1') tot++;
            }
        }
        int mn = 3;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                int ans = 3, curr = 0;
                if(i + 1 < n && j + 1 < m) {
                    if(v[i][j] == '1') curr++;
                    if(v[i + 1][j] == '1') curr++;
                    if(v[i][j + 1] == '1') curr++;
                    if(curr != 0) ans = min(ans, curr);
                }
                curr = 0;
                if(i + 1 < n && j - 1 >= 0) {
                    if(v[i][j] == '1') curr++;
                    if(v[i + 1][j] == '1') curr++;
                    if(v[i][j - 1] == '1') curr++;
                    if(curr != 0) ans = min(ans, curr);
                }
                curr = 0;
                if(i - 1 >= 0 && j + 1 < m) {
                    if(v[i][j] == '1') curr++;
                    if(v[i - 1][j] == '1') curr++;
                    if(v[i][j + 1] == '1') curr++;
                    if(curr != 0) ans = min(ans, curr);
                }
                curr = 0;
                if(i - 1 >= 0 && j - 1 >= 0) {
                    if(v[i][j] == '1') curr++;
                    if(v[i - 1][j] == '1') curr++;
                    if(v[i][j - 1] == '1') curr++;
                    if(curr != 0) ans = min(ans, curr);
                }
                mn = min(mn, ans);
            }
        }
        dbg(mn);
        if(tot != 0) tot -= (mn - 1);
        cout << tot << endl;
    }
}