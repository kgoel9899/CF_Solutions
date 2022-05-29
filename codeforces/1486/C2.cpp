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

// editorial
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        cout << "? " << 1 << " " << n << endl;
        int full;
        cin >> full;
        int ans = -1;
        if(full == 1) {
            // max is in [full + 1, n]
            int beg = full + 1, end = n;
            while(beg <= end) {
                int mid = (beg + end) / 2;
                assert(full != mid);
                cout << "? " << full << " " << mid << endl;
                int curr;
                cin >> curr;
                if(curr == full) {
                    // max is in [beg, mid - 1]
                    end = mid - 1;
                    ans = mid;
                } else {
                    // max is in [mid + 1, end]
                    beg = mid + 1;
                }
            }
        } else {
            cout << "? " << 1 << " " << full << endl;
            int half;
            cin >> half;
            if(half != full) {
                // max is in [full + 1, n]
                int beg = full + 1, end = n;
                while(beg <= end) {
                    int mid = (beg + end) / 2;
                    assert(full != mid);
                    cout << "? " << full << " " << mid << endl;
                    int curr;
                    cin >> curr;
                    if(curr == full) {
                        // max is in [beg, mid - 1]
                        end = mid - 1;
                        ans = mid;
                    } else {
                        // max is in [mid + 1, end]
                        beg = mid + 1;
                    }
                }
            } else {
                // max is in [1, full - 1]
                int beg = 1, end = full - 1;
                while(beg <= end) {
                    int mid = (beg + end) / 2;
                    assert(full != mid);
                    cout << "? " << mid << " " << full << endl;
                    int curr;
                    cin >> curr;
                    if(curr == full) {
                        // max is in [mid + 1, end]
                        beg = mid + 1;
                        ans = mid;
                    } else {
                        // max is in [beg, mid - 1]
                        end = mid - 1;
                    }
                }
            }
        }
        cout << "! " << ans << endl;
    }
}