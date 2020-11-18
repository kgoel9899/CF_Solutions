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
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        int curr = 0, mx = INT_MIN, ans = INT_MAX;
        set<int> s;
        for(int i=0;i<=n;i++) {
            int add = 0;
            if(i >= k) {
                if(s.count(i - k) != 0) {
                    curr--;
                    add++;
                }
                if(s.count(i - 1) != 0) {
                    curr--;
                    add++;
                }
                if(curr > mx) {
                    mx = curr;
                    ans = i - k;
                }
                curr += add;
                add = 0;
                if(s.count(i - k) != 0) curr--;
            }
            if(i < n - 1 && i > 0 && v[i] > v[i + 1] && v[i] > v[i - 1]) {
                s.insert(i);
                curr++;
            }
        }
        cout << mx + 1 << " " << ans + 1 << endl;
    }
}