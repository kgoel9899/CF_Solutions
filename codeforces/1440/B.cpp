#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e18;
int32_t main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> v(n * k);
        for(int i=0;i<n*k;i++) {
            cin >> v[i];
        }
        int tot = (n + 1) / 2, ans = 0;
        if(n % 2 == 0) tot++;
        int x = 0;
        for(int i=n*k-tot;i>=0&&x<k;i-=tot) {
            ans += v[i];
            x++;
        }
        cout << ans << endl;
    }
}