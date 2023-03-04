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

int modRecursive(int a, int b, int c) {
    if(b == 0) return 1;
    if(b == 1) return a;
    int temp = modRecursive(a, b / 2, c);
    if(b % 2 == 0) return (temp * temp) % c;
    else return (a * ((temp * temp) % c)) % c;
}
int modInverse(int n) {
    return modRecursive(n, MOD - 2, MOD);
}
int32_t main() {
    fast;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> ppow1(n), ppow2(n);
        ppow1[0] = ppow2[0] = 1;
        const int p1 = 29, p2 = 31;
        for(int i=1;i<n;i++) {
            ppow1[i] = (ppow1[i - 1] * p1) % MOD;
            ppow2[i] = (ppow2[i - 1] * p2) % MOD;
        }
        // dbg(ppow1);
        dbg(ppow2);
        vector<int> hash1(n), hash2(n);
        hash1[0] = ((s[0] - 'a' + 1) * ppow1[0]) % MOD;
        hash2[0] = ((s[0] - 'a' + 1) * ppow2[0]) % MOD;
        for(int i=1;i<n;i++) {
            hash1[i] = (hash1[i - 1] + (s[i] - 'a' + 1) * ppow1[i]) % MOD;
            hash2[i] = (hash2[i - 1] + (s[i] - 'a' + 1) * ppow2[i]) % MOD;
        }
        // dbg(hash1);
        dbg(hash2);
        set<pair<int, int>> ans;
        for(int i=1;i<n;i++) {
            int x1 = 0;
            if(i - 2 >= 0) x1 = hash1[i - 2];
            int x2 = 0;
            if(i + 1 < n) {
                x2 = (hash1[n - 1] - hash1[i] + MOD) % MOD;
                // x2 /= modRecursive(p1, 2, MOD);
                x2 *= modInverse(modRecursive(p1, 2, MOD));
                x2 %= MOD;
            }
            int x3 = 0;
            if(i - 2 >= 0) x3 = hash2[i - 2];
            int x4 = 0;
            if(i + 1 < n) {
                x4 = (hash2[n - 1] - hash2[i] + MOD) % MOD;
                if(i == 8) dbg(x4);
                // x2 /= modRecursive(p1, 2, MOD);
                x4 *= modInverse(modRecursive(p2, 2, MOD));
                x4 %= MOD;
                if(i == 8) dbg(x3, x4, x3 + x4);
            }
            // int curr1 = (hash1[i] - (i >= 2 ? hash1[i - 2] : 0) + MOD) % MOD;
            // curr1 *= ppow1[n - 1 - (i - 1)];
            // curr1 %= MOD;
            // dbg(curr1);
            // int curr2 = (hash2[i] - (i >= 2 ? hash2[i - 2] : 0) + MOD) % MOD;
            // curr2 *= ppow2[n - 1 - (i - 1)];
            // curr2 %= MOD;
            // dbg(curr2);
            // curr1 = (mult1[n - 1] - curr1 + MOD) % MOD;
            // curr2 = (mult2[n - 1] - curr2 + MOD) % MOD;
            // dbg(i, x1, x2, x1 + x2);
            dbg(i, x1 + x2, x3 + x4);
            int val1 = (x1 + x2) % MOD;
            int val2 = (x3 + x4) % MOD;
            ans.insert({val1, val2});
            // ans.insert({x2});
        }
        cout << ans.size() << endl;
    }
}
// s[3] * p^3 + s[4] * p^4
