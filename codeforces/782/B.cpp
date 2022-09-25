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

bool check(double mid, int n, vector<double>& a, vector<double>& b) {
    double l = -INF, r = INF;
    for(int i=0;i<n;i++) {
        double x = a[i] - b[i] * mid;
        double y = a[i] + b[i] * mid;
        l = max(l, x);
        r = min(r, y);
    }
    return l <= r;
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        vector<double> a(n), b(n);
        for(int i=0;i<n;i++) {
            cin >> a[i];
        }
        for(int i=0;i<n;i++) {
            cin >> b[i];
        }
        double beg = 0, end = 1e12;
        double ans = INF;
        const double eps = 1e-7;
        while(beg <= end) {
            double mid = (beg + end) / 2;
            dbg(mid);
            if(check(mid, n, a, b)) {
                ans = mid;
                end = mid - eps;
            } else beg = mid + eps;
        }
        setpres;
        cout << ans << endl;
    }
}