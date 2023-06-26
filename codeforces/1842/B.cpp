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

bool good(int x, int y) {
    for(int i=31;i>=0;i--) {
        if(((x >> i) & 1) == 1) {
            if(((y >> i) & 1) != 1) return false;
        }
    }
    return true;
}
int32_t main() {
    fast;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        int n, x;
        cin >> n >> x;
        vector<vector<int>> v(3, vector<int>(n));
        for(int i=0;i<3;i++) {
            for(int j=0;j<n;j++) {
                cin >> v[i][j];
            }
        }
        int i = 0, j = 0, k = 0, curr = 0;
        while(i < n || j < n || k < n) {
            if(i < n && good(v[0][i], x)) {
                curr |= v[0][i];
                i++;
            } else if(j < n && good(v[1][j], x)) {
                curr |= v[1][j];
                j++;
            } else if(k < n && good(v[2][k], x)) {
                curr |= v[2][k];
                k++;
            } else break;
        }
        if(curr == x) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}