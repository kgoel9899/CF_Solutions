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
    // cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        map<string, int> m;
        for(int i=0;i<n;i++) {
            int c;
            cin >> c;
            string s;
            cin >> s;
            sort(all(s));
            if(m.find(s) == m.end()) m[s] = c;
            else m[s] = min(m[s], c);
        }
        int ans = INF;
        if(m.find("A") != m.end() && m.find("B") != m.end() && m.find("C") != m.end()) ans = m["A"] + m["B"] + m["C"];
        if(m.find("AB") != m.end() && m.find("C") != m.end()) ans = min(ans, m["AB"] + m["C"]);
        if(m.find("AB") != m.end() && m.find("AC") != m.end()) ans = min(ans, m["AB"] + m["AC"]);
        if(m.find("AB") != m.end() && m.find("BC") != m.end()) ans = min(ans, m["AB"] + m["BC"]);
        if(m.find("AC") != m.end() && m.find("B") != m.end()) ans = min(ans, m["AC"] + m["B"]);
        if(m.find("AC") != m.end() && m.find("BC") != m.end()) ans = min(ans, m["AC"] + m["BC"]);
        if(m.find("BC") != m.end() && m.find("A") != m.end()) ans = min(ans, m["BC"] + m["A"]);
        if(m.find("ABC") != m.end()) ans = min(ans, m["ABC"]);
        if(ans == INF) ans = -1;
        cout << ans << endl;
    }
}