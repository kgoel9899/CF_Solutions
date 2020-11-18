#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e18;
int cost;
bool check(vector<int>& b, vector<int>& p, int n, int m, int a, int mid) {
    cost = 0;
    for(int i=mid-1;i>=0;i--) {
        cost += p[mid - 1 - i];
        if(b[i] < p[mid - 1 - i]) a -= p[mid - 1 - i] - b[i];
    }
    return a >= 0;
}
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--) {
        int n, m, a;
        cin >> n >> m >> a;
        vector<int> b(n), p(m);
        for(int i=0;i<n;i++) {
            cin >> b[i];
        }
        for(int i=0;i<m;i++) {
            cin >> p[i];
        }
        sort(b.begin(), b.end(), greater<int>());
        sort(p.begin(), p.end());
        int r = 0, s = 0;
        int beg = 0, end = min(n, m);
        while(beg <= end) {
            int mid = (beg + end) / 2;
            if(check(b, p, n, m, a, mid)) {
                r = mid;
                s = cost;
                beg = mid + 1;
            } else end = mid - 1;
        }
        cout << r << " " << max(0ll, s - a) << endl;
    }
}