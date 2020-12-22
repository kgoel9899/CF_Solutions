#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e18;
const int N = 205;
int R, G, B;
vector<int> r(N), g(N), b(N);
int dp[N][N][N];
int helper(int x, int y, int z) {
    if(x == R && y == G && z == B) return dp[x][y][z] = 0;
    if(dp[x][y][z] != -1) return dp[x][y][z];
    int ans1 = 0, ans2 = 0, ans3 = 0;
    if(x < R && y < G) ans1 = r[x] * g[y] + helper(x + 1, y + 1, z);
    if(x < R && z < B) ans2 = r[x] * b[z] + helper(x + 1, y, z + 1);
    if(y < G && z < B) ans3 = g[y] * b[z] + helper(x, y + 1, z + 1);
    return dp[x][y][z] = max({ans1, ans2, ans3});
}
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--) {
        cin >> R >> G >> B;
        memset(dp, -1, sizeof(dp));
        for(int i=0;i<R;i++) {
            cin >> r[i];
        }
        for(int i=0;i<G;i++) {
            cin >> g[i];
        }
        for(int i=0;i<B;i++) {
            cin >> b[i];
        }
        sort(r.begin(), r.end(), greater<int>());
        sort(g.begin(), g.end(), greater<int>());
        sort(b.begin(), b.end(), greater<int>());
        cout << helper(0, 0, 0) << endl;
    }
}