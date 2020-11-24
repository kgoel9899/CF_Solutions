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
        vector<pair<int, int>> v(n);
        map<int, int> m;
        for(int i=0;i<n;i++) {
            cin >> v[i].first;
            v[i].second = i + 1;
            m[v[i].first]++;
        }
        // sort(v.begin(), v.end());
        int flag = 0, val;
        for(auto i : m) {
            if(i.second == 1) {
                val = i.first;
                flag = 1;
                break;
            }
        }
        if(flag == 0) cout << -1 << endl;
        else {
            for(auto i : v) {
                if(i.first == val) {
                    cout << i.second << endl;
                    break;
                }
            }
        }
    }
}