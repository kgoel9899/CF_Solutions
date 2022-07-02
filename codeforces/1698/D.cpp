#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
#define setpres cout << fixed << setprecision(10)
#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// #define endl "\n"
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
        int n;
        cin >> n;
        int beg = 0, end = n - 1;
        int ans = -1;
        while(beg <= end) {
            int mid = (beg + end) / 2;
            // left query
            cout << "? " << beg + 1 << " " << mid + 1 << endl;
            int sz = mid - beg + 1;
            vector<int> v(sz);
            int match = 0;
            for(int i=0;i<sz;i++) {
                cin >> v[i];
                if(v[i] >= beg + 1 && v[i] <= mid + 1) match++;
            }
            if(match % 2 == 0) {
                // ans in other part
                beg = mid + 1;
            } else {
                // ans here
                if(sz == 1) {
                    ans = mid + 1;
                    break;
                }
                end = mid;
            }
        }
        assert(ans != -1);
        cout << "! " << ans << endl;
    }
}
// odd number of elements match then here is the answer otherwise other side