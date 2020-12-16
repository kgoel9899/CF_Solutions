#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e18;
const int N = 305;
double dp[N][N][N];
double helper(int one, int two, int three, int n) {
    if(one < 0 || two < 0 || three < 0) return 0;
    if(one == 0 && two == 0 && three == 0) return 0;
    if(dp[one][two][three] > 0.0) return dp[one][two][three];
    return dp[one][two][three] = (n + one * helper(one - 1, two, three, n) + two * helper(one + 1, two - 1, three, n) + three * helper(one, two + 1, three - 1, n)) / (one + two + three);
}
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        memset(dp, 0.0, sizeof(dp));
        int one = 0, two = 0, three = 0;
        for(int i=0;i<n;i++) {
            cin >> v[i];
            if(v[i] == 1) one++;
            else if(v[i] == 2) two++;
            else three++;
        }
        cout << fixed << setprecision(10);
        cout << helper(one, two, three, n) << endl;
    }
}