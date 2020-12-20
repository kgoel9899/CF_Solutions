#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e18;
bool check(vector<int>& v, int n, int k, int mid) {
    int len = 0;
    for(int i=0;i<n;i++) {
        if(len % 2 == 0) {
            if(v[i] <= mid) len++;
        } else len++;
    }
    int len1 = 0;
    for(int i=0;i<n;i++) {
        if(len1 % 2 == 0) len1++;
        else {
            if(v[i] <= mid) len1++;
        }
    }
    return len >= k || len1 >= k;
}
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        int beg = 1, end = 1e9;
        int ans = 1e9;
        while(beg <= end) {
            int mid = (beg + end) / 2;
            if(check(v, n, k, mid)) {
                ans = mid;
                end = mid - 1;
            } else beg = mid + 1;
        }
        cout << ans << endl;
    }
}