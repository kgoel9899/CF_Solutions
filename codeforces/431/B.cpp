#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e18;
const int N = 1e5 + 5;
vector<int> v(N, -1);
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--) {
        vector<vector<int>> v(5, vector<int>(5));
        for(int i=0;i<5;i++) {
            for(int j=0;j<5;j++) {
                cin >> v[i][j];
            }
        }
        vector<int> ans = {0, 1, 2, 3, 4};
        int ret = 0;
        do {
            int a = ans[0], b = ans[1], c = ans[2], d = ans[3], e = ans[4];
            int curr = v[a][b] + v[b][a] + v[c][d] + v[d][c] + v[b][c] + v[c][b] + v[d][e] + v[e][d] + v[c][d] + v[d][c] + v[d][e] + v[e][d];
            ret = max(ret, curr);
        } while(next_permutation(ans.begin(), ans.end()));
        cout << ret << endl;
    }
}