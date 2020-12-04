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
        int n;
        cin >> n;
        vector<string> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        vector<vector<int>> dp1(10, vector<int>(n)); //row left
        vector<vector<int>> dp2(10, vector<int>(n)); //row right
        vector<vector<int>> dp3(10, vector<int>(n)); //col up
        vector<vector<int>> dp4(10, vector<int>(n)); //col down
        vector<vector<int>> row(10, vector<int>(2)), col(10, vector<int>(2));
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                int num = v[i][j] - '0';
                if(dp1[num][i] == 0) dp1[num][i] = j + 1;
                else dp2[num][i] = j + 1;
                if(row[num][0] == 0) row[num][0] = i + 1;
                else row[num][1] = i + 1;
            }
        }
        for(int i=0;i<n;i++) { //col
            for(int j=0;j<n;j++) { //row
                int num = v[j][i] - '0';
                if(dp3[num][i] == 0) dp3[num][i] = j + 1;
                else dp4[num][i] = j + 1;
                if(col[num][0] == 0) col[num][0] = i + 1;
                else col[num][1] = i + 1;
            }
        }
        vector<int> ans(10, 0);
        for(int dig=0;dig<10;dig++) {
            for(int i=0;i<n;i++) { //row
                if(dp2[dig][i] == 0) continue;
                int a = (n - 1 - i) * (dp2[dig][i] - dp1[dig][i]);
                int b = i * (dp2[dig][i] - dp1[dig][i]);
                ans[dig] = max({ans[dig], a, b});
            }
        }
        for(int dig=0;dig<10;dig++) {
            for(int i=0;i<n;i++) { //col
                if(dp4[dig][i] == 0) continue;
                int a = (n - 1 - i) * (dp4[dig][i] - dp3[dig][i]);
                int b = i * (dp4[dig][i] - dp3[dig][i]);
                ans[dig] = max({ans[dig], a, b});
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                int num = v[i][j] - '0';
                if(row[num][1] == 0) continue;
                int mx = max(row[num][1] - i - 1, i + 1 - row[num][0]);
                int a = (n - 1 - j) * mx;
                int b = j * mx;
                ans[num] = max({ans[num], a, b});
            }
        }
        for(int i=0;i<n;i++) { //col
            for(int j=0;j<n;j++) { //row
                int num = v[j][i] - '0';
                if(col[num][1] == 0) continue;
                int mx = max(col[num][1] - i - 1, i + 1 - col[num][0]);
                int a = (n - 1 - j) * mx;
                int b = j * mx;
                ans[num] = max({ans[num], a, b});
            }
        }
        for(auto i : ans) {
            cout << i << " ";
        }
        cout << endl;
    }
}