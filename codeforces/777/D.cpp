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
        vector<string> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        for(int i=n-2;i>=0;i--) {
            string a = v[i];
            string b = v[i + 1];
            int curr = 1, len = min(a.size(), b.size());
            while(curr < len && a[curr] == b[curr]) {
                curr++;
            }
            if(a[curr] > b[curr]) v[i] = a.substr(0, curr);
        }
        for(auto i : v) {
            cout << i << endl;
        }
    }
}