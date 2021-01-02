#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
#define setpres cout << fixed << setprecision(10)
#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e18;
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--) {
        int n;
        cin >> n;
        set<string> s;
        int flag = 0;
        string ans = "";
        for(int i=0;i<n;i++) {
            string st;
            cin >> st;
            if(flag == 1) continue;
            if(st[0] == '!') {
                if(s.count(st.substr(1)) > 0) {
                    cout << st.substr(1) << endl;
                    flag = 1;
                }
            } else {
                string temp = '!' + st;
                if(s.count(temp) > 0) {
                    cout << st << endl;
                    flag = 1;
                }
            }
            s.insert(st);
        }
        if(flag == 0) cout << "satisfiable" << endl;
    }
}