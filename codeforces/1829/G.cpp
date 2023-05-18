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
    const int N = 1500;
    vector<vector<int>> pref(N, vector<int>(N));
    vector<int> ans(1e6 + 5);
    int val = 1;
    for(int i=1;i<N;i++) {
        int r = i, c = 1;
        while(r >= 1) {
            pref[r][c] = val++;
            r--;
            c++;
        }
    }
    // dbg(pref);
    for(int i=1;i<N;i++) {
        for(int j=1;j<N;j++) {
            int val1 = pref[i][j];
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + val1 * val1;
            if(val1 < ans.size()) ans[val1] = pref[i][j];
        }
    }
    while(tt--) {
        int n;
        cin >> n;
        cout << ans[n] << endl;
    }
}