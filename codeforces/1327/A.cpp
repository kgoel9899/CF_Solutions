#include<bits/stdc++.h>
#define MOD 998244353
#define ll long long
#define endl "\n"
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAX 1000005
using namespace std;

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n, k;
        cin >> n >> k;
        if(n < (ll)pow(k, 2)) {
            cout << "NO" << endl;
            continue;
        }
        if(k % 2 == 0 && n % 2 == 1) {
            cout << "NO" << endl;
            continue;
        }
        if(k % 2 == 1 && n % 2 == 0) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
    }
}