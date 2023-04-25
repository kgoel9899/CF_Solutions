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

int diff(string& a, string& b, int m) {
    int ct = 0;
    for(int i=0;i<m;i++) {
        if(a[i] != b[i]) ct++;
    }
    return ct;
}
bool good(vector<string>& v, int n, int m, string& s) {
    for(int i=1;i<n;i++) {
        if(diff(v[i], s, m) > 1) return false;
    }
    return true;
}
int32_t main() {
    fast;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        int n, m;
        cin >> n >> m;
        vector<string> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        int ok = 0;
        for(int i=0;i<m;i++) {
            for(char c='a';c<='z';c++) {
                string s = v[0];
                s[i] = c;
                if(good(v, n, m, s)) {
                    cout << s << endl;
                    ok = 1;
                    break;
                }
            }
            if(ok) break;
        }
        if(!ok) cout << -1 << endl;
    }
}