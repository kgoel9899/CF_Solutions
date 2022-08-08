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

bool pal(string& s) {
    if(s[0] != s[4] || s[1] != s[3]) return false;
    return true;
}
int32_t main() {
    fast;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        string s;
        cin >> s;
        int x;
        cin >> x;
        int h = x / 60, m = x % 60;
        int h2 = stoi(s.substr(0, 2)) + h;
        int m2 = stoi(s.substr(3)) + m;
        if(m2 >= 60) {
            h2++;
            m2 %= 60;
        }
        h2 %= 24;
        // cout << h2 << " " << m2 << endl;
        string a = to_string(h2);
        string b = to_string(m2);
        if(a.size() == 1) a = '0' + a;
        if(b.size() == 1) b = '0' + b;
        string curr = a + ":" + b;
        // dbg(curr);
        int ans = 0;
        ans += pal(s);
        while(curr != s) {
            ans += pal(curr);
            h = x / 60, m = x % 60;
            h2 = stoi(curr.substr(0, 2)) + h;
            m2 = stoi(curr.substr(3)) + m;
            if(m2 >= 60) {
                h2++;
                m2 %= 60;
            }
            h2 %= 24;
            a = to_string(h2);
            b = to_string(m2);
            if(a.size() == 1) a = '0' + a;
            if(b.size() == 1) b = '0' + b;
            curr = a + ":" + b;
            // dbg(curr);
        }
        cout << ans << endl;
    }
}