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

int check(int mid, int n, int m, vector<int>& a, vector<int>& b) {
    int ans = 0;
    for(int i=0;i<n;i++) {
        if(a[i] < mid) ans += mid - a[i];
    }
    for(int i=0;i<m;i++) {
        if(b[i] > mid) ans += b[i] - mid;
    }
    return ans;
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        for(int i=0;i<n;i++) {
            cin >> a[i];
        }
        for(int i=0;i<m;i++) {
            cin >> b[i];
        }
        int ans = INF;
        int beg = 0, end = 1e9;
        while(beg <= end) {
            int mid1 = beg + (end - beg) / 3;
            int mid2 = end - (end - beg) / 3;
            int val1 = check(mid1, n, m, a, b);
            int val2 = check(mid2, n, m, a, b);
            // dbg(val1, mid1, val2, mid2);
            if(val1 > val2) {
                ans = min(ans, val1);
                beg = mid1 + 1;
            } else if(val1 < val2) {
                ans = min(ans, val2);
                end = mid2 - 1;
            } else {
                ans = min(ans, val2);
                beg = mid1 + 1;
                end = mid2 - 1;
            }
        }
        cout << ans << endl;
    }
}