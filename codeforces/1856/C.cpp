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

bool solve(int ind, int mid, int n, int k, vector<int>& v) {
    int ops = 0;
    for(int i=ind;i+1<n;i++) {
        if(mid <= v[i]) break;
        if(i < n - 2) ops += mid - v[i];
        else {
            if(v[n - 1] + 1 < mid) return false;
            ops += mid - v[i];
        }
        mid--;
    }
    return ops <= k;
}
int32_t main() {
    fast;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        int ans = *max_element(all(v));
        for(int i=0;i<n-1;i++) {
            int beg = v[i], end = 1e9;
            int curr = v[i];
            while(beg <= end) {
                int mid = (beg + end) / 2;
                if(solve(i, mid, n, k, v)) {
                    curr = mid;
                    beg = mid + 1;
                    // dbg(i, mid);
                } else end = mid - 1;
            }
            // dbg(i, curr);
            ans = max(ans, curr);
        }
        cout << ans << endl;
    }
}