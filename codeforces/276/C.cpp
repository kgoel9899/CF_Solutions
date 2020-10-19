#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
#define MOD 1000000007
#define int long long
#define ld long double
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--) {
        int n, q;
        cin >> n >> q;
        vector<int> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        vector<int> pref(n + 1);
        while(q--) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            pref[a]++;
            pref[b + 1]--;
        }
        for(int i=1;i<=n;i++) {
            pref[i] += pref[i - 1];
        }
        vector<int> temp;
        for(int i=0;i<=n;i++) {
            if(pref[i] > 0) temp.push_back(pref[i]);
        }
        sort(v.begin(), v.end(), greater<int>());
        sort(temp.begin(), temp.end(), greater<int>());
        int ans = 0, x = 0;
        for(auto i : temp) {
            ans += i * v[x++];
        }
        cout << ans << endl;
    }
}