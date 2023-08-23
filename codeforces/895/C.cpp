#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
// #define int long long
#define setpres cout << fixed << setprecision(10)
#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
// const int INF = 1e18;

#ifdef DEBUG
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }

int n, sz;
vector<int> primes;
int dp[71][1ll << 19];
const int N = 71;
map<int, int> m;
bool prime(int num) {
    for(int i=2;i*i<=num;i++) {
        if(num % i == 0) return false;
    }
    return true;
}
int get(int num, int mask) {
    for(int i=0;i<sz;i++) {
        int ct = 0;
        while(num % primes[i] == 0) {
            num /= primes[i];
            ct++;
        }
        if(ct % 2) mask ^= (1 << i);
    }
    return mask;
}
int modRecursive(int a, int b, int c) {
    if(b == 0) return 1;
    int temp = modRecursive(a, b / 2, c);
    if(b % 2 == 0) return ((long long)temp * temp) % c;
    else return ((long long)a * (((long long)temp * temp) % c)) % c;
}
int solve(int curr, int mask) {
    if(curr == N) return !mask;
    if(dp[curr][mask] != -1) return dp[curr][mask];
    if(m[curr] == 0) return dp[curr][mask] = solve(curr + 1, mask);
    int new_mask = get(curr, mask);
    int ct = modRecursive(2, m[curr] - 1, MOD);
    int op1 = ((long long)ct * solve(curr + 1, new_mask)) % MOD;
    int op2 = ((long long)ct * solve(curr + 1, mask)) % MOD;
    return dp[curr][mask] = ((long long)op1 + op2) % MOD;
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        cin >> n;
        m.clear();
        for(int i=0;i<n;i++) {
            int x;
            cin >> x;
            m[x]++;
        }
        primes.clear();
        for(int i=2;i<N;i++) {
            if(prime(i)) primes.push_back(i);
        }
        sz = primes.size();
        memset(dp, -1, sizeof dp);
        int ans = solve(0, 0) - 1;
        ans += MOD;
        ans %= MOD;
        cout << ans << endl;
    }
} 