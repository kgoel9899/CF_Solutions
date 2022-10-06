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

int n;
vector<int> v, groups;
vector<vector<int>> dp;
bool solve(int curr, int sum, int nn) {
    if(sum > n) return false;
    if(curr == nn) return sum == n;
    if(dp[curr][sum] != -1) return dp[curr][sum];
    return dp[curr][sum] = solve(curr + 1, sum, nn) || solve(curr + 1, sum + groups[curr], nn);
}
int32_t main() {
    fast;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        cin >> n;
        v.clear();
        v.resize(2 * n);
        for(int i=0;i<2*n;i++) {
            cin >> v[i];
        }
        set<int> s;
        for(int i=1;i<=2*n;i++) {
            s.insert(i);
        }
        groups.clear();
        int len = 1;
        for(int i=2*n-1;i>=0;i--) {
            if(v[i] == *s.rbegin()) {
                groups.push_back(len);
                len = 0;
            }
            s.erase(v[i]);
            len++;
        }
        reverse(all(groups));
        dbg(groups);
        dp.clear();
        dp.resize(groups.size(), vector<int>(n + 1, -1));
        if(solve(0, 0, groups.size())) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}