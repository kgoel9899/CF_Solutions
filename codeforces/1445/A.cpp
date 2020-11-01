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
        int n, x;
        cin >> n >> x;
        vector<int> v(n), v1(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        for(int i=0;i<n;i++) {
            cin >> v1[i];
        }
        int flag = 0;
        sort(v.begin(), v.end());
        sort(v1.begin(), v1.end(), greater<int>());
        for(int i=0;i<n;i++) {
            if(v[i] + v1[i] > x) {
                flag = 1;
                break;
            }
        }
        if(flag == 0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}