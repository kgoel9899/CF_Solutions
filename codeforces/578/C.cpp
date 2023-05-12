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

double solve(double mid, int n, vector<int>& v) {
    double s1 = 0, mx1 = -INF;
    for(auto& i : v) {
        s1 += i - mid;
        mx1 = max(mx1, s1);
        if(s1 < 0) s1 = 0;
    }
    double s2 = 0, mx2 = -INF;
    for(auto& i : v) {
        s2 += mid - i;
        mx2 = max(mx2, s2);
        if(s2 < 0) s2 = 0;
    }
    return max(mx1, mx2);
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        double l = -1e5, r = 1e5;
        while(r - l > 1e-12) {
            double mid1 = l + (r - l) / 3;
            double mid2 = r - (r - l) / 3;
            double val1 = solve(mid1, n, v);
            double val2 = solve(mid2, n, v);
            if(val1 > val2) l = mid1;
            else if(val1 < val2) r = mid2;
            else {
                l = mid1;
                r = mid2;
            }
        }
        setpres;
        cout << solve(l, n, v);
    }
}