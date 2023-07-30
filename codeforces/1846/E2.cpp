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
        int n;
        cin >> n;
        if(n < 7) {
            cout << "NO" << endl;
            continue;
        }
        const int MX = 1e18;
        int done = 0;
        for(int p=2;p<63;p++) {
            int beg = 2, end = 1e9;
            while(beg <= end) {
                int r = (beg + end) / 2;
                int val = 1 + r + r * r;
                int fact = r * r;
                int too = 0;
                for(int i=3;i<=p;i++) {
                    if(fact > MX / r) {
                        too = 1;
                        break;
                    }
                    fact *= r;
                    val += fact;
                }
                if(too == 0) {
                    if(val == n) {
                        done = 1;
                        break;
                    } else if(val > n) end = r - 1;
                    else beg = r + 1;
                } else end = r - 1;
            }
            if(done) break;
        }
        if(done) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}