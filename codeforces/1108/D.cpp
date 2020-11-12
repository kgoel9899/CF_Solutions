#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        char curr = s[0];
        int ct = 1;
        vector<int> v;
        for(int i=1;i<n;i++) {
            if(s[i] == curr) ct++;
            else {
                v.push_back(ct);
                ct = 1;
                curr = s[i];
            }
        }
        v.push_back(ct);
        int ans = 0;
        for(auto i : v) {
            ans += i / 2;
        }
        cout << ans << endl;
        int x = 0;
        for(int i=0;i<v.size();i++) {
            // cout << x << endl;
            if(v[i] == 1) {
                x++;
                continue;
            }
            if(x + v[i] >= n) {
                int fin = x + v[i];
                x++;
                // cout << x << endl;
                // cout << fin << endl;
                for(;x<fin;x+=2) {
                    if(s[x - 1] == 'R' || s[x - 1] == 'G') s[x] = 'B';
                    else s[x] = 'R';
                }
                x = fin;
            } else {
                char curr = s[x + v[i]];
                int fin = x + v[i];
                x++;
                for(;x<fin;x+=2) {
                    if(curr == 'R') {
                        if(s[x - 1] == 'G') s[x] = 'B';
                        else s[x] = 'G';
                    } else if(curr == 'G') {
                        if(s[x - 1] == 'R') s[x] = 'B';
                        else s[x] = 'R';
                    } else {
                        if(s[x - 1] == 'G') s[x] = 'R';
                        else s[x] = 'G';
                    }
                }
                x = fin;
            }
        }
        cout << s << endl;
    }
}