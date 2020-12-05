#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e18;
int32_t main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        string a, b;
        cin >> a >> b;
        vector<int> s(26), t(26);
        for(auto i : a) {
            s[i - 'a']++;
        }
        for(auto i : b) {
            t[i - 'a']++;
        }
        int flag = 0;
        for(int i=0;i<25;i++) {
            if(s[i] < t[i]) {
                flag = 1;
                break;
            }
            s[i] -= t[i];
            if(s[i] % k != 0) {
                flag = 1;
                break;
            }
            s[i + 1] += s[i];
        }
        if(flag == 0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}