#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
#define MOD 1000000007
#define int long long
#define ld long double
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--) {
        int x = 0, y = 0;
        for(int i=0;i<5;i++) {
            for(int j=0;j<5;j++) {
                int num;
                cin >> num;
                if(num == 1) {
                    x = i;
                    y = j;
                }
            }
        }
        cout << abs(2 - x) + abs(2 - y) << endl;
    }
}