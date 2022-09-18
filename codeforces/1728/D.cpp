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

string s;
int n;
vector<vector<int>> dp;
int solve(int i, int j) {
    if(i > j) return 0;
    assert(i != j);
    
    if(dp[i][j] != -1) return dp[i][j];

    // Alice i, Bob i + 1
    int op1 = solve(i + 2, j);
    int ans1;
    if(op1) ans1 = op1;
    else {
        if(s[i] < s[i + 1]) ans1 = 1;
        else if(s[i] > s[i + 1]) ans1 = 2;
        else ans1 = 0;
    }

    // Alice i, Bob j
    int op2 = solve(i + 1, j - 1);
    int ans2;
    if(op2) ans2 = op2;
    else {
        if(s[i] < s[j]) ans2 = 1;
        else if(s[i] > s[j]) ans2 = 2;
        else ans2 = 0;
    }

    if(ans1 == 1 && ans2 == 1) {
        // Alice wins after picking i and no matter what Bob chooses afterwards (i + 1 or j)
        return dp[i][j] = 1;
    }

    // Alice j, Bob j - 1
    int op3 = solve(i, j - 2);
    int ans3;
    if(op3) ans3 = op3;
    else {
        if(s[j] < s[j - 1]) ans3 = 1;
        else if(s[j] > s[j - 1]) ans3 = 2;
        else ans3 = 0;
    }

    // Alice j, Bob i
    int op4 = solve(i + 1, j - 1);
    int ans4;
    if(op4) ans4 = op4;
    else {
        if(s[j] < s[i]) ans4 = 1;
        else if(s[j] > s[i]) ans4 = 2;
        else ans4 = 0;
    }

    if(ans3 == 1 && ans4 == 1) {
        // Alice wins after picking j and no matter what Bob chooses afterwards (i or j - 1)
        return dp[i][j] = 1;
    }

    if(ans1 == 2 && ans2 == 2 && ans3 == 2 && ans4 == 2) {
        // if bob wins in all the 4 cases
        return dp[i][j] = 2;
    }

    return dp[i][j] = 0;
}
int32_t main() {
    fast;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        cin >> s;
        n = s.size();
        dp.clear();
        dp.resize(n + 1, vector<int>(n + 1, -1));
        int ans = solve(0, n - 1);
        if(ans == 1) cout << "Alice" << endl;
        else if(ans == 2) cout << "Bob" << endl;
        else cout << "Draw" << endl;
    }
}