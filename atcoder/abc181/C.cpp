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
        vector<pair<int, int>> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i].first >> v[i].second;
        }
        int flag = 0;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                for(int k=j+1;k<n;k++) {
                    int x = v[j].first - v[i].first;
                    int y = v[j].second - v[i].second;
                    int g = __gcd(x, y);
                    x /= g;
                    y /= g;
                    int a = v[k].first - v[j].first;
                    int b = v[k].second - v[j].second;
                    g = __gcd(a, b);
                    a /= g;
                    b /= g;
                    if(a == x && b == y) {
                        flag = 1;
                        break;
                    }
                }
                if(flag == 1) break;
            }
            if(flag == 1) break;
        }
        if(flag == 1) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}