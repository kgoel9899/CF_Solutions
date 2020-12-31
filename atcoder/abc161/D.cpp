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
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--) {
        int k;
        cin >> k;
        queue<int> q;
        for(int i=1;i<=9;i++) {
            q.push(i);
        }
        int ans;
        while(k--) {
            ans = q.front();
            q.pop();
            if(ans % 10 != 0) q.push(ans * 10 + ans % 10 - 1);
            q.push(ans * 10 + ans % 10);
            if(ans % 10 != 9) q.push(ans * 10 + ans % 10 + 1);
        }
        cout << ans << endl;
    }
}