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
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int n = s.size(), ct = 0;
        int a = 0, b = 0;
        for(int i=0;i<n;i++) {
            if(s[i] == 'A') a++;
            else b++;
        }
        for(int i=0;i<n;i++) {
            if(s[i] == 'A') ct++;
            else {
                if(ct > 0) {
                    ct--;
                    a--;
                    b--;
                }
            }
        }
        if(a != 0) cout << a + b % 2 << endl;
        else cout << b % 2 << endl;
        // cout << a << " " << b << endl;
    }
}