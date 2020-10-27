#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
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
        string s;
        cin >> s;
        int ans = 0;
        for(int i=1;i<n;i++) {
            if(s[i] == s[i - 1]) ans++;
        }
        cout << (ans + 1) / 2 << endl;
    }
    return 0;
}