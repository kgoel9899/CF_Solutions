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
    // cin >> t;
    while(t--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n), k(q);
        for(int i=0;i<n;i++) {
            cin >> a[i];
        }
        for(int i=0;i<q;i++) {
            cin >> k[i];
        }
        vector<int> v = a;
        for(int i=1;i<n;i++) {
            v[i] += v[i - 1];
        }
        int tot = 0;
        for(int i=0;i<q;i++) {
            int ans = n;
            int beg = 0, end = n - 1;
            while(beg <= end) {
                int mid = (beg + end) / 2;
                if(v[mid] - tot >= k[i]) {
                    ans = mid;
                    end = mid - 1;
                }
                else beg = mid + 1;
            }
            if(ans == n) {
                cout << n << endl;
                tot = 0;
                continue;
            }
            if(v[ans] - tot == k[i]) {
                if(ans == n - 1) {
                    cout << n << endl;
                    tot = 0;
                } else {
                    cout << n - ans - 1 << endl;
                    tot += k[i];
                }
            } else if(v[ans] - tot > k[i]) {
                cout << n - ans << endl;
                tot += k[i];
            }
        }
    }
}
//1,3,6,10