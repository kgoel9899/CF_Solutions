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

bool all9(string& s) {
    for(auto& i : s) {
        if(i != '9') return false;
    }
    return true;
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
        if(s[0] != '9') {
            for(auto& i : s) {
                cout << '9' - i;
            }
        } else {
            string ans = "";
            int carry = 0;
            for(int i=n-1;i>=0;i--) {
                int curr = carry + (s[i] - '0');
                if(curr >= 2) {
                    ans += char('0' + (11 - curr));
                    carry = 1;
                } else {
                    ans += char('0' + (1 - curr));
                    carry = 0;
                }
            }
            reverse(all(ans));
            cout << ans;
        }
        cout << endl;
    }
}