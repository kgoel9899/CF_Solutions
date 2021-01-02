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
        vector<pair<int, int>> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i].first >> v[i].second;
        }
        int ct = 0;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                double a = v[j].first - v[i].first;
                double b = v[j].second - v[i].second;
                double sl = b / a;
                if(sl <= 1 && sl >= -1) ct++;
            }
        }
        cout << ct << endl;
    }
}