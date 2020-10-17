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
        int n;
        cin >> n;
        vector<int> v(n);
        double b = 0;
        int a = 0, c = 0;
        for(int i=0;i<n;i++) {
            cin >> v[i];
            a += abs(v[i]);
            b += v[i] * v[i];
            c = max(c, abs(v[i]));
        }
        cout << fixed << setprecision(12);
        cout << a << endl;
        cout << sqrt(b) << endl;
        cout << c << endl;
    }
}