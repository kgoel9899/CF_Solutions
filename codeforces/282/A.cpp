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
    int x = 0;
    while(t--) {
        string s;
        cin >> s;
        if(s[0] == 'X') {
            if(s.substr(1) == "++") x++;
            else x--;
        } else {
            if(s.substr(0, 2) == "++") x++;
            else x--;
        }
    }
    cout << x << endl;
}