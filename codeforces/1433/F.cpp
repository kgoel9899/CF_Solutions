#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e18;
const int N = 71;
int dp[N][N][N][N], v[N][N];
int32_t main() {
    int t = 1;
    // cin >> t;
    while(t--) {
        int n, m, tot;
        cin >> n >> m >> tot;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                cin >> v[i][j];
            }
        }
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                for(int k=0;k<N;k++) {
                    for(int l=0;l<N;l++) {
                        dp[i][j][k][l] = -INF;
                    }
                }
            }
        }
        dp[0][0][0][0] = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                for(int k=0;k<=m/2;k++) {
                    for(int l=0;l<tot;l++) {
                        if(j < m - 1) {
                            dp[i][j + 1][k][l] = max(dp[i][j + 1][k][l], dp[i][j][k][l]);
                            if(k < m / 2) dp[i][j + 1][k + 1][(l + v[i][j]) % tot] = max(dp[i][j + 1][k + 1][(l + v[i][j]) % tot], dp[i][j][k][l] + v[i][j]);
                        } else {
                            dp[i + 1][0][0][l] = max(dp[i + 1][0][0][l], dp[i][j][k][l]);
                            if(k < m / 2) dp[i + 1][0][0][(l + v[i][j]) % tot] = max(dp[i + 1][0][0][(l + v[i][j]) % tot], dp[i][j][k][l] + v[i][j]);
                        }
                    }
                }
            }
        }
        cout << dp[n][0][0][0] << endl;
    }
    return 0;
}