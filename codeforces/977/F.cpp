#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e18;
int32_t main() {
    int t = 1;
    // cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        map<int, int> m;
        int mx = 0, save = -1;
        for(int i=0;i<n;i++) {
            m[v[i]] = m[v[i] - 1] + 1;
            if(m[v[i]] > mx) {
                mx = m[v[i]];
                save = v[i];
            }
        }
        vector<int> ans;
        for(int i=n-1;i>=0;i--) {
            if(v[i] == save) {
                ans.push_back(i + 1);
                save--;
            }
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << endl;
        for(auto i : ans) {
            cout << i << " ";
        }
        cout << endl;
    }
}