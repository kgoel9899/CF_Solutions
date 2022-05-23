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

bool check(vector<int>& a, vector<int>& b, int n, int m, int mid) {
    for(int i=0;i<n;i++) {
        int one = a[i] - mid;
        int two = a[i] + mid;
        auto it = lower_bound(all(b), one);
        auto it1 = upper_bound(all(b), two);
        if(it == it1) return false;
    }
    return true;
}
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        for(int i=0;i<n;i++) {
            cin >> a[i];
        }
        for(int i=0;i<m;i++) {
            cin >> b[i];
        }
        int beg = 0, end = 1e10;
        int ans = end;
        while(beg <= end) {
            int mid = (beg + end) / 2;
            if(check(a, b, n, m, mid)) {
                ans = mid;
                end = mid - 1;
            } else beg = mid + 1;
        }
        cout << ans << endl;
    }
}