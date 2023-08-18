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
        string s1, s2;
        cin >> s1 >> s2;
        int n = s1.size();
        int t, q;
        cin >> t >> q;
        int diff = 0;
        for(int i=0;i<n;i++) {
            if(s1[i] != s2[i]) diff++;
        }
        map<int, int> block;
        for(int i=1;i<=q;i++) {
            if(block.find(i - t) != block.end()) {
                int ind = block[i - t];
                if(s1[ind] != s2[ind]) diff++;
            }
            int type;
            cin >> type;
            if(type == 1) {
                int ind;
                cin >> ind;
                ind--;
                block[i] = ind;
                if(s1[ind] != s2[ind]) diff--;
            } else if(type == 2) {
                int x, ind1, y, ind2;
                cin >> x >> ind1 >> y >> ind2;
                ind1--;
                ind2--;
                diff -= (s1[ind1] != s2[ind1]);
                diff -= (s1[ind2] != s2[ind2]);
                if(x == 1) {
                    if(y == 1) swap(s1[ind1], s1[ind2]);
                    else swap(s1[ind1], s2[ind2]);
                } else {
                    if(y == 1) swap(s2[ind1], s1[ind2]);
                    else swap(s2[ind1], s2[ind2]);
                }
                diff += (s1[ind1] != s2[ind1]);
                diff += (s1[ind2] != s2[ind2]);
            } else {
                if(diff == 0) cout << "YES" << endl;
                else cout << "NO" << endl;
            }
        }
    }
}