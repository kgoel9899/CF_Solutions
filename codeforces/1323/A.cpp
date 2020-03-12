#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
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
        int arr[n];
        int ans = -1;
        for(int i=0;i<n;i++) {
            cin >> arr[i];
            if(arr[i] % 2 == 0) {
                ans = i;
            }
        }
        if(ans != -1) {
            cout << 1 << endl;
            cout << ans + 1 << endl;
        } else {
            if(n >= 2) {
                cout << 2 << endl;
                cout << 1 << " " << 2 << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }
}