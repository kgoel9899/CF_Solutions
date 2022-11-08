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
        // cin >> tt;
        while(tt--) {
            int n;
            cin >> n;
            vector<vector<int>> v(n + 1, vector<int>(n + 1));
            for(int i=1;i<=n;i++) {
                for(int j=1;j<=n;j++) {
                    cin >> v[i][j];
                }
            }
            int m;
            cin >> m;
            vector<vector<int>> rem(m, vector<int>(3));
            for(int i=0;i<m;i++) {
                cin >> rem[i][0] >> rem[i][1] >> rem[i][2];
            }
            for(int k=0;k<m;k++) {
                int ans = 0;
                int a = rem[k][0], b = rem[k][1], c = rem[k][2];
                for(int i=1;i<=n;i++) {
                    for(int j=1;j<=n;j++) {
                        v[i][j] = min({v[i][j], v[i][a] + v[b][j] + c, v[i][b] + v[a][j] + c});
                        ans += v[i][j];
                    }
                }
                cout << ans / 2 << " ";
            }
        }
    }