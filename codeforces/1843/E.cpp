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

bool solve(int mid, int n, int m, vector<vector<int>>& v, vector<int>& q) {
    vector<int> pref(n);
    for(int i=0;i<=mid;i++) {
        pref[q[i] - 1] = 1;
    }
    for(int i=1;i<n;i++) {
        pref[i] += pref[i - 1];
    }
    dbg(pref);
    for(auto& i : v) {
        int curr = pref[i[1] - 1];
        if(i[0] >= 2) curr -= pref[i[0] - 2];
        if(curr > i[1] - i[0] + 1 - curr) return true;
    }
    return false;
}
int32_t main() {
    fast;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> v(m, vector<int>(2));
        for(int i=0;i<m;i++) {
            cin >> v[i][0] >> v[i][1];
        }
        int tot;
        cin >> tot;
        vector<int> q(tot);
        for(int i=0;i<tot;i++) {
            cin >> q[i];
        }
        int beg = 0, end = tot - 1;
        int ans = tot;
        while(beg <= end) {
            int mid = (beg + end) / 2;
            if(solve(mid, n, tot, v, q)) {
                ans = mid;
                end = mid - 1;
            } else beg = mid + 1;
        }
        if(ans == tot) cout << -1 << endl;
        else cout << ans + 1 << endl;
    }
}