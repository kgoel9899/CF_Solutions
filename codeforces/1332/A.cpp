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
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        ll x, y, x1, y1, x2, y2;
        cin >> x >> y >> x1 >> y1 >> x2 >> y2;
        if(a > b) {
            if(x - (a - b) < x1) {
                cout << "No" << endl;
                continue;
            }
        } else {
            if(x + (b - a) > x2) {
                cout << "No" << endl;
                continue;
            }
        }
        if(c > d) {
            if(y - (c - d) < y1) {
                cout << "No" << endl;
                continue;
            }
        } else {
            if(y + (d - c) > y2) {
                cout << "No" << endl;
                continue;
            }
        }
        if(x == x1 && x == x2 && (a > 0 || b > 0)) {
            cout << "No" << endl;
            continue;
        }
        if(y == y1 && y == y2 && (c > 0 || d > 0)) {
            cout << "No" << endl;
            continue;
        }
        cout << "Yes" << endl;
    }
}