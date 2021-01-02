#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
#define setpres cout << fixed << setprecision(10)
#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e8;
bool check(vector<int>& v, int n, int m, int a, int b, int mid) {
    if(abs(a - b) <= mid) return false;
    int tot = 0;
    if(a < b) tot = b - 1;
    else tot = n - b;
    int ct = 0, x = 0;
    for(int i=mid;i>=1;i--) {
        if(v[i] + x < tot) ct++;
        x++;
    }
    if(ct < mid) return false;
    return true;
}
int32_t main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--) {
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        vector<int> v(m + 1);
        for(int i=1;i<=m;i++) {
            cin >> v[i];
        }
        int beg = 0, end = m;
        int ans = 0;
        sort(v.begin(), v.end());
        while(beg <= end) {
            int mid = (beg + end) / 2;
            if(check(v, n, m, a, b, mid)) {
                ans = mid;
                beg = mid + 1;
            } else end = mid - 1;
        }
        cout << ans << endl;
    }
}