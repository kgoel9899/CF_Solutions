#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e18;
bool comp(pair<int, int> a, pair<int, int> b) {
    return a.first - a.second > b.first - b.second;
}
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> v(n);
        int sum = 0;
        for(int i=0;i<n;i++) {
            cin >> v[i].first >> v[i].second;
            sum += v[i].first;
        }
        sort(v.begin(), v.end(), comp);
        // for(auto i : v) {
        //     cout << i .first << " " << i.second << endl;
        // }
        if(sum <= m) {
            cout << 0 << endl;
            continue;
        }
        int ct = 0;
        for(auto i : v) {
            sum -= i.first - i.second;
            ct++;
            if(sum <= m) break;
        }
        if(sum <= m) cout << ct << endl;
        else cout << -1 << endl;
    }
}