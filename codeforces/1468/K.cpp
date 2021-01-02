#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
#define setpres cout << fixed << setprecision(10)
#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e8;
int32_t main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int x = 0, y = 0;
        set<pair<int, int>> st;
        for(auto i : s) {
            if(i == 'L') x--;
            else if(i == 'R') x++;
            else if(i == 'U') y++;
            else y--;
            st.insert({x, y});
        }
        int flag = 0;
        for(auto i : st) {
            x = 0, y = 0;
            pair<int, int> p = i;
            for(auto j : s) {
                if(j == 'L') x--;
                else if(j == 'R') x++;
                else if(j == 'U') y++;
                else y--;
                if(x == p.first && y == p.second) {
                    if(j == 'L') x++;
                    else if(j == 'R') x--;
                    else if(j == 'U') y--;
                    else y++;
                }
            }
            if(x == 0 && y == 0) {
                cout << p.first << " " << p.second << endl;
                flag = 1;
                break;
            }
        }
        if(flag == 0) cout << 0 << " " << 0 << endl;
    }
}