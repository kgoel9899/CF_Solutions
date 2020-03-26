#include<bits/stdc++.h>
#define MOD 998244353
#define ll long long
#define endl "\n"
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAX 1000005
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        ll a, b;
        cin >> a >> b;
        if(a % b == 0) {
            cout << 0 << endl;
        } else {
            cout << (a / b + 1) * b - a << endl;
        }
    }
}