#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e18;
const int mx = 1e5 + 5;
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        vector<vector<int>> ans;
        for(int i=0;i<n;i++) {
            int mn = INT_MAX, ind = -1;
            for(int j=i+1;j<n;j++) {
                if(v[j] < mn) {
                    mn = v[j];
                    ind = j;
                }
            }
            if(v[i] <= mn) continue;
            else {
                ans.push_back({i, ind});
                swap(v[i], v[ind]);
            }
        }
        cout << ans.size() << endl;
        for(auto i : ans) {
            cout << i[0] << " " << i[1] << endl;
        }
    }
}