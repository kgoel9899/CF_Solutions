#include<bits/stdc++.h>
#define ll long long int
#define MAX 8200
#define MOD 1000000000
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int h, m;
        cin >> h >> m;
        int ans = 60 - m;
        ans += (23 - h) * 60;
        cout << ans << endl;
    }
}