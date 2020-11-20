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
    // cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int a, b;
        cin >> a;
        vector<int> v1(a);
        for(int i=0;i<a;i++) {
            cin >> v1[i];
        }
        cin >> b;
        vector<int> v2(b);
        for(int i=0;i<b;i++) {
            cin >> v2[i];
        }
        int ans = 0;
        while(v1.size() > 0 && v2.size() > 0 && ans < 10000) {
            ans++;
            a = v1[0];
            b = v2[0];
            if(a > b) {
                v1.push_back(b);
                v1.push_back(a);
            } else {
                v2.push_back(a);
                v2.push_back(b);
            }
            v1.erase(v1.begin());
            v2.erase(v2.begin());
        }
        if(ans == 10000) cout << -1 << endl;
        else {
            cout << ans << " ";
            if(v1.size() == 0) cout << 2 << endl;
            else cout << 1 << endl;
        }
    }
}