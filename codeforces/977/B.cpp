#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e18;
int32_t main() {
    int t = 1;
    // cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = 0;
        string st = "";
        for(int i=0;i<n-1;i++) {
            string curr = s.substr(i, 2);
            int ct = 0;
            for(int j=0;j<n-1;j++) {
                if(curr == s.substr(j, 2)) ct++;
            }
            if(ans < ct) {
                ans = ct;
                st = curr;
            }
        }
        cout << st << endl;
    }
}