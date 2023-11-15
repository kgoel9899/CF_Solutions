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
        string s;
        cin >> s;
        int n = s.size();
        int ok = 0;
        for(int i=n-1;i>0;i--) {
            int a = (s[i - 1] - '0');
            int b = (s[i] - '0');
            int sum = a + b;
            if(sum >= 10) {
                ok = 1;
                s[i - 1] = '0' + sum / 10;
                s[i] = '0' + sum % 10;
                break;
            }
        }
        if(ok) cout << s << endl;
        else {
            string s1 = s.substr(1);
            s1[0] = '0' + ((s[0] - '0') + (s[1] - '0'));
            cout << s1 << endl;
        }
    }
}