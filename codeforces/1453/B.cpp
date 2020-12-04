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
        int n;
        cin >> n;
        vector<int> v(n);
        set<int> s;
        for(int i=0;i<n;i++) {
            cin >> v[i];
            s.insert(v[i]);
        }
        if(s.size() == 1) {
            cout << 0 << endl;
            continue;
        }
        int ans = INF, curr = 0;
        for(int i=n-2;i>=0;i--) {
            curr += abs(v[i] - v[i + 1]);
        }
        ans = curr;
        for(int i=1;i<n-1;i++) {
            int temp = curr;
            // v[i] = v[i - 1];
            temp -= abs(v[i] - v[i - 1]);
            int diff1 = abs(v[i + 1] - v[i]);
            int diff2 = abs(v[i + 1] - v[i - 1]);
            temp -= diff1;
            temp += diff2;
            ans = min(ans, temp);
            temp = curr;
            // v[i] = v[i + 1];
            temp -= abs(v[i] - v[i + 1]);
            diff1 = abs(v[i] - v[i - 1]);
            diff2 = abs(v[i + 1] - v[i - 1]);
            temp -= diff1;
            temp += diff2;
            // if(diff1 >= diff2) 
            ans = min(ans, temp);
        }
        // v[0] = v[1];
        vector<int> nv = v;
        nv[0] = nv[1];
        int a = 0, b = 0;
        for(int i=n-2;i>=0;i--) {
            a += abs(nv[i] - nv[i + 1]);
        }
        nv = v;
        nv[n - 1] = nv[n - 2];
        for(int i=n-2;i>=0;i--) {
            b += abs(nv[i] - nv[i + 1]);
        }
        cout << min({ans, a, b}) << endl;
    }
}