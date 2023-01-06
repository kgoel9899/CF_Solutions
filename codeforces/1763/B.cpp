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
        int n, k;
        cin >> n >> k;
        vector<vector<int>> v(n, vector<int>(2));
        for(int i=0;i<n;i++) {
            cin >> v[i][1];
        }
        for(int i=0;i<n;i++) {
            cin >> v[i][0];
        }
        sort(all(v));
        dbg(v);
        int sub = 0, ok = 1;
        for(int i=0;i<n;i++) {
            v[i][1] -= sub;
            if(v[i][1] <= 0) continue;
            if(i > 0) k -= v[i][0];
            dbg(i, k, v[i][0], v[i][1]);
            if(v[i][1] - k <= 0) {
                sub += k;
                continue;
            }
            int beg = 1, end = v[i][1];
            int ans = 0;
            dbg(beg, end, k);
            while(beg <= end) {
                int mid = (beg + end) / 2;
                int newk = k - (mid - 1) * v[i][0];
                dbg(newk);
                if(newk < 0) {
                    end = mid - 1;
                    continue;
                }
                int curr = v[i][1] - mid * k + (v[i][0] * (mid - 1) * (2 + (mid - 2))) / 2;
                dbg(mid, curr);
                if(curr <= 0) {
                    ans = mid;
                    end = mid - 1;
                } else beg = mid + 1;
            }
            if(ans == 0) {
                ok = 0;
                break;
            }
            dbg(ans);
            sub += ans * k - (v[i][0] * (ans - 1) * (2 + (ans - 2))) / 2;
            k -= (ans - 1) * v[i][0];
            dbg(sub, k);
        }
        if(ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
// 9 - k - (k - mn) - (k - 2*mn) <= 0
// val - x*k + mn*(1..x-1)