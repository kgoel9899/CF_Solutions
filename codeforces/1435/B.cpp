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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> v(n, vector<int>(m));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                cin >> v[i][j];
            }
        }
        vector<int> col;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                int num;
                cin >> num;
                if(i == 0) col.push_back(num);
            }
        }
        int ind;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(v[i][j] == col[0]) {
                    ind = j;
                    break;
                }
            }
        }
        map<int, int> mp;
        for(int i=0;i<n;i++) {
            mp[v[i][ind]] = i;
        }
        vector<int> ans;
        for(auto i : col) {
            ans.push_back(mp[i]);
        }
        for(auto i : ans) {
            for(int j=0;j<m;j++) {
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}