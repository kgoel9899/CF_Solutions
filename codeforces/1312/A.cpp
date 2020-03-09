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
        int n, m;
        cin >> n >> m;
        if(n % m == 0 || m % n == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}