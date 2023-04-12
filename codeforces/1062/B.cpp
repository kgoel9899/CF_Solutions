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
    // cin >> tt;
    const int N = 1e6 + 5;
    vector<int> sieve(N);
    for(int i=0;i<N;i++) {
        sieve[i] = i;
    }
    for(int i=2;i<N;i++) {
        if(sieve[i] == i) {
            for(int j=2*i;j<N;j+=i) {
                if(sieve[j] == j) sieve[j] = i;
            }
        }
    }
    while(tt--) {
        int n;
        cin >> n;
        if(n == 1) {
            cout << 1 << " " << 0 << endl;
            continue;
        }
        int mx = -1, mn = INF;
        int ans = 1;
        while(n > 1) {
            int div = sieve[n];
            int ct = 0;
            while(n % div == 0) {
                ct++;
                n /= div;
            }
            ans *= div;
            mx = max(mx, ct);
            mn = min(mn, ct);
        }
        int lg = log2(mx);
        cout << ans << " ";
        dbg(lg, mx, mn);
        if(pow(2, lg) == mx) cout << lg + (mn != mx) << endl;
        else cout << lg + 2 << endl;
    }
}