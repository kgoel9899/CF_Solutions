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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> v(n, vector<int>(m));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                cin >> v[i][j];
            }
        }
        int ans = 0;
        map<pair<int, int>, int> mpx, mpy;
        mpx[{0, 0}]++;
        mpy[{n - 1, m - 1}]++;
        dbg(mpx);
        dbg(mpy);
        while(mpx.size() != 0 || mpy.size() != 0) {
            map<pair<int, int>, int> tempx, tempy;
            int one = 0, zero = 0;
            for(auto i : mpx) {
                if(mpy.find(i.first) == mpy.end()) {
                    // assert(i.second == 1);
                    if(v[i.first.first][i.first.second] == 1) one++;
                    else zero++;
                }
            }
            for(auto i : mpy) {
                if(mpx.find(i.first) == mpx.end()) {
                    // assert(i.second == 1);
                    if(v[i.first.first][i.first.second] == 1) one++;
                    else zero++;
                }
            }
            ans += min(one, zero);
            for(auto i : mpx) {
                int nx = i.first.first + 1, ny = i.first.second;
                if(nx < n) tempx[{nx, ny}]++;
                nx = i.first.first;
                ny = i.first.second + 1;
                if(ny < m) tempx[{nx, ny}]++;
            }
            for(auto i : mpy) {
                int nx = i.first.first - 1, ny = i.first.second;
                if(nx >= 0) tempy[{nx, ny}]++;
                nx = i.first.first;
                ny = i.first.second - 1;
                if(ny >= 0) tempy[{nx, ny}]++;
            }
            dbg(tempx, ans, one, zero);
            dbg(tempy, ans);
            mpx = tempx;
            mpy = tempy;
        }
        assert(ans % 2 == 0);
        cout << ans / 2 << endl;
    }
}