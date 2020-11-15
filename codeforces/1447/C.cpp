#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define rep(i, a, b) for(int i=a;i<b;i++)
const int INF = 1e18;
int32_t main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--) {
        int n, w;
        cin >> n >> w;
        vector<pair<int, int>> v(n);
        rep(i, 0, n) {
            cin >> v[i].first;
            v[i].second = i + 1;
        }
        sort(v.begin(), v.end(), greater<pair<int, int>>());
        int sum = 0;
        vector<int> ans;
        rep(i, 0, n) {
            if(sum + v[i].first <= w) {
                sum += v[i].first;
                ans.push_back(v[i].second);
            }
        }
        if(sum >= (w + 1) / 2 && sum <= w && ans.size() != 0) {
            cout << ans.size() << endl;
            for(auto i : ans) {
                cout << i << " ";
            }
            cout << endl;
        } else cout << -1 << endl;
    }
}