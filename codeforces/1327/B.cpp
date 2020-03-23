#include<bits/stdc++.h>
#define MOD 998244353
#define ll long long
#define endl "\n"
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAX 1000005
using namespace std;

int main() {
    fast;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> vis(n + 1, 0);
        vector<int> nott;
        for(int i=0;i<n;i++) {
            int k;
            cin >> k;
            vector<int> temp;
            for(int j=0;j<k;j++) {
                int num;
                cin >> num;
                temp.push_back(num);
            }
            int j = 0;
            for(;j<k;j++) {
                if(vis[temp[j]] == 0) {
                    vis[temp[j]] = 1;
                    break;
                }
            }
            if(j >= k) {
                nott.push_back(i);
            }
        }
        int i = 1;
        for(;i<=n;i++) {
            if(vis[i] == 0) {
                cout << "IMPROVE" << endl;
                cout << nott[0] + 1 << " " << i << endl;
                break;
            }
        }
        if(i > n) {
            cout << "OPTIMAL" << endl;
        }
    }
}