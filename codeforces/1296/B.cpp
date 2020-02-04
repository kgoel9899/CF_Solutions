#include<bits/stdc++.h>
#define ll long long int
#define MAX 8200
#define MOD 1000000000
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        ll s;
        cin >> s;
        ll sp = 0;
        while(s >= 10) {
            ll div = s / 10;
            ll rem = s % 10;
            s /= 10;
            s += rem;
            sp += div * 10;
        }
        cout << sp + s << endl;
    }
}