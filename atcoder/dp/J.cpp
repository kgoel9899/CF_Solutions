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

// we are not interested in the order of plates, we just want to know the number of plates with every number of sushi in it
// dp[i][j][k][l] = ans for i 3s, j 2s, k 1s, l 0s -> i + j + k + l = n -> we can remove 1 state
// dp[i][j][k] = ans for i 3s, j 2s, k 1s
// dp[i][j][k] = p3 * dp[i - 1][j + 1][k] + p2 * dp[i][j - 1][k + 1] + p1 * dp[i][j][k - 1] + p0 * dp[i][j][k] -- self dependency
// dp[i][j][k] = (p3 * dp[i - 1][j + 1][k] + p2 * dp[i][j - 1][k + 1] + p1 * dp[i][j][k - 1]) / (1 - p0)
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        map<int, int> m;
        for(int i=0;i<n;i++) {
            int num;
            cin >> num;
            m[num]++;
        }
        vector<vector<vector<double>>> dp(n + 5, vector<vector<double>>(n + 5, vector<double>(n + 5)));
        dp[0][0][0] = 0;
        setpres;
        // this order is important
        for(int three=0;three<=n;three++) {
            for(int two=0;two<=n;two++) {
                for(int one=0;one<=n;one++) {
                    double p3 = 1.0 * three / n;
                    double p2 = 1.0 * two / n;
                    double p1 = 1.0 * one / n;
                    double p0 = 1.0 * (n - three - two - one) / n;
                    if(one + two + three == 0 || one + two + three > n) continue;
                    dp[three][two][one] = 1; // because atleast one of one, two, three will be > 0, so we will eat 1 sushi
                    if(three - 1 >= 0) dp[three][two][one] += p3 * dp[three - 1][two + 1][one];
                    if(two - 1 >= 0) dp[three][two][one] += p2 * dp[three][two - 1][one + 1];
                    if(one - 1 >= 0) dp[three][two][one] += p1 * dp[three][two][one - 1];
                    dp[three][two][one] /= (1.0 - p0);
                }
            }
        }
        cout << dp[m[3]][m[2]][m[1]] << endl;
    }
}