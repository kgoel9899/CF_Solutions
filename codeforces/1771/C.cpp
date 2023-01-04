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
    const int N = 1e5 + 5;
    vector<int> sieve(N, 1), primes;
    sieve[0] = 0;
    sieve[1] = 0;
    for(int i=2;i*i<=N;i++) {
        if(sieve[i]) {
            for(int j=i*i;j<N;j+=i) {
                sieve[j] = 0;
            }
        }
    }
    dbg(sieve);
    for(int i=2;i<N;i++) {
        if(sieve[i]) primes.push_back(i);
    }
    while(tt--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        map<int, int> m;
        dbg(primes);
        for(int i=0;i<n;i++) {
            int curr = v[i];
            for(auto& j : primes) {
                if(j * j > curr) break;
                int ct = 0;
                while(curr % j == 0) {
                    ct++;
                    curr /= j;
                }
                if(ct) m[j]++;
            }
            if(curr > 1) m[curr]++;
        }
        dbg(m);
        int ok = 0;
        for(auto& i : m) {
            if(i.second >= 2) {
                ok = 1;
                break;
            }
        }
        if(ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}