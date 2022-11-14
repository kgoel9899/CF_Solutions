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

const int N = 1e5 + 5;
const int LOG = 17;
int sparse[N][LOG][5];
int query(int l, int r, int ind) {
    int len = r - l + 1;
    int lg = log2(len);
    return max(sparse[l][lg][ind], sparse[r - (1 << lg) + 1][lg][ind]);
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> v(n, vector<int>(m));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                cin >> v[i][j];
                sparse[i][0][j] = v[i][j];
            }
        }
        for(int j=1;j<LOG;j++) {
            for(int i=0;i+(1<<(j-1))<n;i++) {
                for(int kk=0;kk<m;kk++) {
                    sparse[i][j][kk] = max(sparse[i][j - 1][kk], sparse[i + (1 << (j - 1))][j - 1][kk]);
                }
            }
        }
        int fin = 0;
        vector<int> ans(m);
        for(int i=0;i<n;i++) {
            int beg = i, end = n - 1;
            while(beg <= end) {
                int mid = (beg + end) / 2, curr = 0;
                vector<int> temp(m);
                for(int q=0;q<m;q++) {
                    int ind = query(i, mid, q);
                    curr += ind;
                    temp[q] = ind;
                }
                if(curr <= k) {
                    int len = mid - i + 1;
                    if(len > fin) {
                        fin = len;
                        ans = temp;
                    }
                    beg = mid + 1;
                } else end = mid - 1;
            }
        }
        for(auto i : ans) {
            cout << i << " ";
        }
        cout << endl;
    }
}