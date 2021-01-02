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
        string a, b;
        cin >> a >> b;
        int s1 = 0, s2 = 0;
        for(auto i : a) {
            s1 += i - '0';
        }
        for(auto i : b) {
            s2 += i - '0';
        }
        if(s1 >= s2) cout << s1 << endl;
        else cout << s2 << endl;
    }
}