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
    set<vector<int>> s;
    for(int i=0;i<=9;i++) {
        for(int j=0;j<=9;j++) {
            for(int k=0;k<=9;k++) {
                int curr = i + j + k;
                if(curr % 10 == 3) {
                    vector<int> t = {i, j, k};
                    sort(all(t));
                    s.insert(t);
                }
            }
        }
    }
    // dbg(s);
    dbg(s.size());
    while(tt--) {
        int n;
        cin >> n;
        vector<int> v(n);
        map<int, int> m;
        for(int i=0;i<n;i++) {
            cin >> v[i];
            m[v[i] % 10]++;
        }
        int ok = 0;
        for(auto i : s) {
            int a = i[0], b = i[1], c = i[2];
            if(m.find(a) == m.end()) continue;
            if(m.find(b) == m.end()) continue;
            if(m.find(c) == m.end()) continue;
            m[a]--;
            m[b]--;
            m[c]--;
            if(m[a] >= 0 && m[b] >= 0 && m[c] >= 0) {
                ok = 1;
                break;
            }
            m[a]++;
            m[b]++;
            m[c]++;
        }
        if(ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}