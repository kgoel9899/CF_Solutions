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
        vector<int> ans;
        int n = s.size();
        if(s[n - 1] <= s[0]) {
            map<char, vector<int>, greater<char>> m;
            for(int i=0;i<n;i++) {
                m[s[i]].push_back(i);
            }
            auto it = m.find(s[0]);
            while(it != m.end()) {
                if(it->first < s[n - 1]) break;
                for(auto i : it->second) {
                    ans.push_back(i);
                }
                it++;
            }
        } else {
            map<char, vector<int>> m;
            for(int i=0;i<n;i++) {
                m[s[i]].push_back(i);
            }
            auto it = m.find(s[0]);
            while(it != m.end()) {
                if(it->first > s[n - 1]) break;
                for(auto i : it->second) {
                    ans.push_back(i);
                }
                it++;
            }
        }
        cout << abs(s[n - 1] - s[0]) << " " << ans.size() << endl;
        for(auto i : ans) {
            cout << i + 1 << " ";
        }
        cout << endl;
    }
}