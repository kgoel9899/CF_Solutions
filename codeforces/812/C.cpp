#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e18;
int cost = 0;
bool check(vector<int>& v, int n, int k, int s) {
    cost = 0;
    vector<int> temp;
    for(int i=0;i<n;i++) {
        temp.push_back(v[i] + (i + 1) * k);
    }
    sort(temp.begin(), temp.end());
    for(int i=0;i<k;i++) {
        cost += temp[i];
    }
    return cost <= s;
}
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--) {
        int n, s;
        cin >> n >> s;
        vector<int> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        int beg = 0, end = n;
        int ans = 0, tot = 0;
        while(beg <= end) {
            int mid = (beg + end) / 2;
            if(check(v, n, mid, s)) {
                beg = mid + 1;
                tot = mid;
                ans = cost;
            } else end = mid - 1;
        }
        cout << tot << " " << ans << endl;
    }
}