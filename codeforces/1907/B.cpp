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
        vector<pair<int, char>> up, low;
        for(int i=0;i<n;i++) {
            char c = s[i];
            if(c == 'b') {
                if(low.size()) low.pop_back();
            } else if(c == 'B') {
                if(up.size()) up.pop_back();
            } else {
                if(isupper(c)) up.push_back({i, c});
                else low.push_back({i, c});
            }
        }
        string ans = "";
        int i = 0, j = 0;
        while(i < low.size() && j < up.size()) {
            if(low[i].first < up[j].first) {
                ans += low[i].second;
                i++;
            } else {
                ans += up[j].second;
                j++;
            }
        }
        while(i < low.size()) {
            ans += low[i].second;
            i++;
        }
        while(j < up.size()) {
            ans += up[j].second;
            j++;
        }
        cout << ans << endl;
    }
}