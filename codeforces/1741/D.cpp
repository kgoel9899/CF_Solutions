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

int solve(int l, int r, vector<int>& v) {
    // dbg(l, r);
    // return 0;
    if(l >= r) return 0;
    int mid = (l + r) / 2;
    int left = solve(l, mid, v);
    int right = solve(mid + 1, r, v);
    if(left == -1 || right == -1) return -1;
    int mn1 = INF, mx1 = -INF;
    for(int i=l;i<=mid;i++) {
        mn1 = min(mn1, v[i]);
        mx1 = max(mx1, v[i]);
    }
    int mn2 = INF, mx2 = -INF;
    for(int i=mid+1;i<=r;i++) {
        mn2 = min(mn2, v[i]);
        mx2 = max(mx2, v[i]);
    }
    int ans = left + right;
    if(mx2 < mn1 || mx1 < mn2) {
        if(mx2 < mn1) {
            // swap
            for(int i=l,j=mid+1;i<=mid;i++,j++) {
                swap(v[i], v[j]);
            }
            return ans + 1;
        } else return ans;
    } else return -1;
}
int32_t main() {
    fast;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        cout << solve(0, n - 1, v) << endl;
    }
}