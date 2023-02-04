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
    const int N = 1e6;
    vector<int> primes, sieve(N, 1);
    sieve[0] = 0;
    sieve[1] = 0;
    for(int i=2;i<N;i++) {
        if(sieve[i]) {
            primes.push_back(i);
            for(int j=i*i;j<N;j+=i) {
                sieve[j] = 0;
            }
        }
    }
    // dbg(primes);
    while(tt--) {
        int n;
        cin >> n;
        int ans = 0;
        vector<pair<int, int>> v;
        for(auto& i : primes) {
            int ct = 0;
            while(n % i == 0) {
                ct++;
                n /= i;
            }
            if(ct == 0) continue;
            v.push_back({i, ct});
        }
        dbg(n);
        if(n >= 2) v.push_back({n, 1});
        dbg(v);
        while(true) {
            int prod = 1;
            for(auto& i : v) {
                if(i.second) {
                    prod *= i.first;
                    i.second--;
                }
            }
            if(prod == 1) break;
            ans += prod;
        }
        cout << ans << endl;
    }
}