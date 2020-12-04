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
        int n, k, s;
        cin >> n >> k >> s;
        int mx = (n - 1) * k;
        if(s > mx || k > s) {
            cout << "NO" << endl;
            continue;
        }
        if(n == 2) {
            cout << "YES" << endl;
            int curr = 1;
            while(k--) {
                if(curr == 1) cout << 2 << endl;
                else cout << 1 << endl;
                curr ^= 1;
            }
            continue;
        }
        int div = (s - k) / (n - 2);
        int temp = div * (n - 1);
        int rem = k - div;
        vector<int> ans;
        int curr = 1;
        for(int i=0;i<div;i++) {
            if(curr == 1) {
                ans.push_back(n);
                curr = n;
            } else {
                ans.push_back(1);
                curr = 1;
            }
        }
        k -= ans.size();
        int reqd = s - temp;
        // cout <<
        // return 0;
        if(curr == 1) {
            if(k > 0) {
                ans.push_back(1 + reqd - k + 1);
                k--;
                int pl = 1;
                while(k--) {
                    if(pl == 1) ans.push_back(ans.back() + 1);
                    else ans.push_back(ans.back() - 1);
                    pl ^= 1;
                }
            }
        } else {
            if(k > 0) {
                ans.push_back(n - reqd + k - 1);
                k--;
                int pl = 1;
                while(k--) {
                    if(pl == 1) ans.push_back(ans.back() + 1);
                    else ans.push_back(ans.back() - 1);
                    pl ^= 1;
                }
            }
        }
        cout << "YES" << endl;
        for(auto i : ans) {
            cout << i << " ";
        }
        cout << endl;
    }
}