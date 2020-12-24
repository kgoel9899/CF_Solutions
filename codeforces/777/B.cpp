#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
#define setpres cout << fixed << setprecision(10)
#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e18;
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        vector<int> v1, v2;
        for(auto i : a) {
            v1.push_back(i - '0');
        }
        for(auto i : b) {
            v2.push_back(i - '0');
        }
        int ans1 = 0, ans2 = 0;
        vector<int> vv = v2;
        sort(all(v1));
        sort(all(vv));
        for(auto i : v1) {
            int ind = lower_bound(all(vv), i) - vv.begin();
            if(ind == vv.size()) {
                ans1++;
                vv.pop_back();
            }
            else vv.erase(vv.begin() + ind);
        }
        vv = v2;
        sort(all(vv));
        for(auto i : v1) {
            int ind = upper_bound(all(vv), i) - vv.begin();
            if(ind == vv.size()) vv.pop_back();
            else {
                ans2++;
                vv.erase(vv.begin() + ind);   
            }
        }
        cout << ans1 << endl;
        cout << ans2 << endl;
    }
}