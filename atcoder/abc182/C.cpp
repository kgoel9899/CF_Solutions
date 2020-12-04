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
        int n;
        cin >> n;
        string s = to_string(n);
        int sum = 0;
        map<int, int> m;
        for(auto i : s) {
            sum += i - '0';
            m[(i - '0') % 3]++;
        }
        if(sum % 3 == 0) cout << 0 << endl;
        else {
            int diff = sum - (sum / 3) * 3;
            if(diff == 1) {
                if(m[1] > 0) {
                    if(s.size() > 1) cout << 1 << endl;
                    else cout << -1 << endl;
                } else {
                    if(m[2] >= 2) {
                        if(s.size() > 2) cout << 2 << endl;
                        else cout << -1 << endl;
                    } else cout << -1 << endl;
                }
            } else {
                if(m[2] > 0) {
                    if(s.size() > 1) cout << 1 << endl;
                    else cout << -1 << endl;
                } else {
                    if(m[1] >= 2) {
                        if(s.size() > 2) cout << 2 << endl;
                        else cout << -1 << endl;
                    }
                }
            }
        }
    }
}