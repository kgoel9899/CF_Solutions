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

void solve(int curr, string& good, int n, int k, set<char>& vis, string& a, string& b, int& ans) {
    if(k == 0) {
        int sz = a.size();
        int mx = 0, temp = 0;
        for(int i=0;i<sz;i++) {
            if(vis.find(a[i]) != vis.end() || a[i] == b[i]) {
                temp++;
                mx += temp;
            } else temp = 0;
        }
        ans = max(ans, mx);
        return;
    }
    if(curr == n) return;
    solve(curr + 1, good, n, k, vis, a, b, ans);
    vis.insert(good[curr]);
    solve(curr + 1, good, n, k - 1, vis, a, b, ans);
    vis.erase(good[curr]);
}
int32_t main() {
    fast;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        int n, k;
        cin >> n >> k;
        string a, b;
        cin >> a >> b;
        set<char> s(all(a));
        if(s.size() <= k) {
            cout << (n * (n + 1)) / 2 << endl;
            continue;
        }
        int ans = 0;
        string good = "";
        for(auto& i : s) {
            good += i;
        }
        set<char> vis;
        solve(0, good, good.size(), k, vis, a, b, ans);
        cout << ans << endl;
    }
}