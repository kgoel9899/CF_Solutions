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

const int N = 2e5 + 5;
const int LOG = 20;
int sparse1[N][LOG], sparse2[N][LOG];
int logs[N], v[N];
int n;
int query1(int l, int r) {
    int len = r - l + 1;
    int lg = logs[len];
    return min(sparse1[l][lg], sparse1[r - (1 << lg) + 1][lg]);
}
int query2(int l, int r) {
    int len = r - l + 1;
    int lg = logs[len];
    return max(sparse2[l][lg], sparse2[r - (1 << lg) + 1][lg]);
}
int32_t main() {
    fast;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        cin >> n;
        for(int i=0;i<n;i++) {
            cin >> v[i];
            sparse1[i][0] = v[i];
            sparse2[i][0] = v[i];
        }
        for(int i=2;i<=n;i++) {
            logs[i] = logs[i / 2] + 1;
        }
        for(int j=1;j<LOG;j++) {
            for(int i=0;i+(1<<(j-1))-1<n;i++) {
                sparse1[i][j] = min(sparse1[i][j - 1], sparse1[i + (1 << (j - 1))][j - 1]);
            }
        }
        for(int j=1;j<LOG;j++) {
            for(int i=0;i+(1<<(j-1))-1<n;i++) {
                sparse2[i][j] = max(sparse2[i][j - 1], sparse2[i + (1 << (j - 1))][j - 1]);
            }
        }
        int done = 0;
        int a = 0;
        for(int i=0;i<n-2;i++) {
            a = max(a, v[i]);
            int beg = i + 1, end = n - 2;
            int l = -1, r = -1;
            while(beg <= end) {
                int mid = (beg + end) / 2;
                int temp = query1(i + 1, mid);
                if(temp == a) {
                    l = mid;
                    end = mid - 1;
                } else if(temp < a) end = mid - 1;
                else beg = mid + 1;
            }
            beg = i + 1, end = n - 2;
            while(beg <= end) {
                int mid = (beg + end) / 2;
                int temp = query1(i + 1, mid);
                if(temp == a) {
                    r = mid;
                    beg = mid + 1;
                } else if(temp < a) end = mid - 1;
                else beg = mid + 1;
            }
            if(l == -1) continue;
            // dbg(i, a, l, r);
            beg = l + 1, end = n - 1;
            int ans = -1;
            while(beg <= end) {
                int mid = (beg + end) / 2;
                int temp = query2(mid, n - 1);
                if(temp == a) {
                    ans = mid;
                    end = mid - 1;
                } else if(temp > a) beg = mid + 1;
                else end = mid - 1;
            }
            // dbg(ans);
            if(ans > l && ans <= r + 1) {
                done = 1;
                cout << "YES" << endl;
                cout << i + 1 << " " << ans - i - 1 << " " << n - ans << endl;
                break;
            }
        }
        if(!done) cout << "NO" << endl;
    }
}