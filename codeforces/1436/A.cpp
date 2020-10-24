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
        int n, m;
        cin >> n >> m;
        vi v(n);
        int s = 0;
        for(int i=0;i<n;i++) {
            cin >> v[i];
            s += v[i];
        }
        if(s == m) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}