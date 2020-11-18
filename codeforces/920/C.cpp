#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e18;
const int mx = 1e5 + 5;
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        string s;
        cin >> s;
        vector<int> temp;
        for(int i=0;i<n;i++) {
            if(s[i] == '1') temp.push_back(v[i]);
            else {
                if((i == n - 1 && s[n - 2] == '1') || (i > 0 && s[i - 1] == '1')) {
                    temp.push_back(v[i]);
                    sort(temp.begin(), temp.end());
                    int x = 0;
                    for(int j=i-(int)temp.size()+1;j<=i;j++) {
                        v[j] = temp[x++];
                    }
                    temp.clear();
                }
            }
        }

        int flag = 0;
        for(int i=1;i<n;i++) {
            if(v[i] < v[i - 1]) {
                flag = 1;
                break;
            }
        }
        if(flag == 1) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}