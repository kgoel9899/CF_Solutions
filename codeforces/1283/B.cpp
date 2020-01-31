#include<bits/stdc++.h>
#define ll long long int
#define MAX 8200
#define MOD 1000000000
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        int factor = n / k, rem = n % k;
        ll ans = factor * k;
        ans += min(rem, k / 2);
        cout << ans << endl;
    }
}