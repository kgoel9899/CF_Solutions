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
        int n, m, k;
        cin >> n >> m >> k;
        int i = 0, j = 0, x = 0;
        int save = k;
        while(k > 1) {
            cout << "2 ";
            cout << i + 1 << " " << j + 1 << " ";
            if(x == 0) {
                j++;
                if(j == m) {
                    j--;
                    i++;
                    x = 1;
                }
            } else {
                j--;
                if(j == -1) {
                    j++;
                    i++;
                    x = 0;
                }
            }
            cout << i + 1 << " " << j + 1 << endl;
            if(x == 0) {
                j++;
                if(j == m) {
                    j--;
                    i++;
                    x = 1;
                }
            } else {
                j--;
                if(j == -1) {
                    j++;
                    i++;
                    x = 0;
                }
            }
            k--;
        }
        int ans = n * m - 2 * (save - 1);
        cout << ans << " ";
        while(ans--) {
            cout << i + 1 << " " << j + 1 << " ";
            if(x == 0) {
                j++;
                if(j == m) {
                    j--;
                    i++;
                    x = 1;
                }
            } else {
                j--;
                if(j == -1) {
                    j++;
                    i++;
                    x = 0;
                }
            }
        }
        cout << endl;
    }
}