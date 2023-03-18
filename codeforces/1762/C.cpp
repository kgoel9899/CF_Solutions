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
int32_t main() {
    fast;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        s = '#' + s;
        n++;
        int ans = 1;
        int one = 0, zero = 0, open = 0;
        if(s[1] == '1') one++;
        else zero++;
        for(int i=2;i<n;i++) {
            if(s[i] == '1') one++;
            else zero++;
            open++;
            int req = i;
            if(s[i] == '1') {
                int diff = req - one;
                one += diff;
                open -= diff;
            } else {
                int diff = req - zero;
                zero += diff;
                open -= diff;
            }
            ans += modRecursive(2, open, mod);
            ans %= mod;
        }
        cout << ans << endl;
    }
}