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
    while(tt--) {
        int n;
        cin >> n;
        map<char, int> m1, m2;
        m1['a']++;
        m2['a']++;
        while(n--) {
            int d, k;
            cin >> d >> k;
            string s;
            cin >> s;
            if(d == 1) {
                for(auto i : s) {
                    m1[i] += k;
                }
            } else {
                for(auto i : s) {
                    m2[i] += k;
                }
            }
            int x = m1.size(), y = m2.size();
            if(x == 1) {
                if(y == 1) {
                    if(m1['a'] < m2['a']) cout << "YES" << endl;
                    else cout << "NO" << endl;
                } else cout << "YES" << endl;
            } else {
                if(y == 1) cout << "NO" << endl;
                else cout << "YES" << endl;
            }
        }
    }
}