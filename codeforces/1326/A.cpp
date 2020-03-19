#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAX 1000005
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        if(n == 1) {
            cout << -1 << endl;
            continue;
        }
        for(int i=0;i<n-1;i++) {
            cout << 9;
        }
        cout << 8 << endl;
    }
}
