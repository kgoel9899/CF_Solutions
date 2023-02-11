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

pair<int, int> solve(int n) {
    if(n % 2 == 0) return {n / 2, n / 2};
    if(n % 10 != 9) return {n / 2, n / 2 + 1};
    auto ans = solve(n / 10);
    string x = to_string(ans.first);
    string y = to_string(ans.second);
    int p = 0, q = 0;
    for(auto& i : x) {
        p += (i - '0');
    }
    for(auto& i : y) {
        q += (i - '0');
    }
    dbg(n, ans);
    if(p >= q) return {ans.first * 10 + 4, ans.second * 10 + 5};
    else return {ans.first * 10 + 5, ans.second * 10 + 4};
}
int32_t main() {
    fast;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        if(n % 2 == 0) {
            cout << n / 2 << " " << n / 2 << endl;
            continue;
        }
        if(n % 10 != 9) {
            cout << n / 2 << " " << n / 2 + 1 << endl;
            continue;
        }
        dbg("here");
        auto ans = solve(n);
        cout << ans.first << " " << ans.second << endl;
    }
}