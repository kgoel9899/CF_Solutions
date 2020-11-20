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
        // vector<int> v(n);
        // for(int i=0;i<n;i++) {
        //     cin >> v[i];
        // }
        string s;
        cin >> s;
        int a = 0, b = 0;
        int ans = 0;
        string fin = "";
        string temp = "";
        for(int i=0;i<n;i++) {
            if(s[i] == 'a') a++;
            else b++;
            temp += s[i];
            if(i >= 1 && i % 2 == 1) {
                if(a == b) {
                    fin += temp;
                    temp = "";
                    continue;
                } else {
                    fin += "ab";
                    ans += (max(a, b) - min(a, b)) / 2;
                    a = (a + b) / 2;
                    b = a;
                    temp = "";
                }
            }
        }
        cout << ans << endl;
        cout << fin << endl;
    }
}