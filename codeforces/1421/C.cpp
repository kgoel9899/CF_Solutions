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
        string s;
        cin >> s;
        int n = s.size();
        cout << 3 << endl;
        cout << "L 2" << endl;
        n++;
        cout << "R " << 2 << endl;
        n += n - 2;
        cout << "R " << n - 1 << endl;
    }
}