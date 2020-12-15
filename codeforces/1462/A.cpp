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
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        vector<int> ans(n);
        int i = 0, j = n - 1;
        int x = 0;
        while(i < j) {
            ans[x] = v[i];
            x++;
            i++;
            ans[x] = v[j];
            x++;
            j--;
        }
        ans[x] = v[i];
        for(int i=0;i<n;i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}