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
        int p;
        cin >> p;
        int curr = 0;
        for(auto i : s) {
            curr += (i - 'a') + 1;
        }
        if(curr <= p) {
            cout << s << endl;
            continue;
        }
        map<char, int, greater<char>> m;
        map<char, int, greater<char>> rem;
        for(auto i : s) {
            m[i]++;
        }
        dbg(m);
        for(auto& i : m) {
            while(curr > p && i.second) {
                curr -= (i.first - 'a') + 1;
                i.second--;
                rem[i.first]++;
            }
        }
        dbg(rem);
        string ans = "";
        for(auto i : s) {
            if(rem.find(i) != rem.end()) {
                rem[i]--;
                if(rem[i] == 0) rem.erase(i);
            } else ans += i;
        }
        cout << ans << endl;
    }
}