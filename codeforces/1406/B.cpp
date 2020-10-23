#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define vi vector<int>
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define pb push_back
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e18;
int32_t main() {
    int t = 1;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vi v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        sort(all(v));
        int a = v[0] * v[1] * v[2] * v[3] * v[4];
        int b = v[0] * v[1] * v[2] * v[3] * v[n - 1];
        int c = v[0] * v[1] * v[2] * v[n - 2] * v[n - 1];
        int d = v[0] * v[1] * v[n - 3] * v[n - 2] * v[n - 1];
        int e = v[0] * v[n - 4] * v[n - 3] * v[n - 2] * v[n - 1];
        int f = v[n - 5] * v[n - 4] * v[n - 3] * v[n - 2] * v[n - 1];
        cout << max({a, b, c, d, e, f}) << endl;
    }
    return 0;
}