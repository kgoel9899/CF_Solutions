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
        string s;
        cin >> s;
        if(n <= 2) {
            cout << stoll(s) << endl;
            continue;
        }
        int ans = INF;
        if(n == 3) {
            ans = min(ans, stoll(s.substr(0, 1)) + stoll(s.substr(1)));
            ans = min(ans, stoll(s.substr(0, 2)) + stoll(s.substr(2)));
            ans = min(ans, stoll(s.substr(0, 1)) * stoll(s.substr(1)));
            ans = min(ans, stoll(s.substr(0, 2)) * stoll(s.substr(2)));
            cout << ans << endl;
            continue;
        }
        int z = 0;
        for(auto& i : s) {
            if(i == '0') z = 1;
        }
        if(z) {
            cout << 0 << endl;
            continue;
        }
        for(int i=1;i<n;i++) {
            int curr = (s[i - 1] - '0') * 10 + (s[i] - '0');
            vector<int> temp;
            for(int j=0;j<i-1;j++) {
                temp.push_back(s[j] - '0');
            }
            temp.push_back(curr);
            for(int j=i+1;j<n;j++) {
                temp.push_back(s[j] - '0');
            }
            int here = 0;
            for(auto& j : temp) {
                if(j != 1) here += j;
            }
            ans = min(ans, here);
        }
        cout << ans << endl;
    }
}    