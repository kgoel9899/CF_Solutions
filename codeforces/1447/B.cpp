#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define vi vector<int>
#define rep(i, a, b) for(int i=a;i<b;i++)
const int INF = 1e18;
int32_t main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<vi> v(n, vi(m));
        int sum = 0, ct = 0, mn = INT_MAX;
        rep(i, 0, n) {
            rep(j, 0, m) {
                int num;
                cin >> num;
                sum += abs(num);
                if(num <= 0) ct++;
                mn = min(mn, abs(num));
            }
        }
        if(ct % 2 == 0) cout << sum << endl;
        else cout << sum - 2 * mn << endl;
    }
}