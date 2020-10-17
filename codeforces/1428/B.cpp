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
        int n;
        cin >> n;
        string s;
        cin >> s;
        int left = 0, right = 0;
        for(int i=0;i<n;i++) {
            if(s[i] == '>') right++;
            else if(s[i] == '<') left++;
        }
        int ans = 0;
        for(int i=0;i<n;i++) {
            if(s[i] == '-' || s[(i - 1 + n) % n] == '-') ans++;
            else {
                if(s[i] == '>') {
                    if(left == 0) ans++;
                } else {
                    if(right == 0) ans++;
                }
            }
        }
        cout << ans << endl;
    }
}