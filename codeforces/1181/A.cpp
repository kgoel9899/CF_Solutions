#include<iostream>
#include<iomanip>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<algorithm>
#include<unordered_set>
//#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAX 200010
using namespace std;
int main() {
    fast;
    ll x, y, z;
    cin >> x >> y >> z;
    ll remx = x % z;
    ll remy = y % z;
    ll divx = x / z;
    ll divy = y / z;
    if(remx == 0 || remy == 0) {
        cout << divx + divy << " " << 0 << endl;
    } else {
        ll a = remx;
        ll b = remy;
        if(b > a) {
            if(a + b >= z) {
                cout << divx + divy + 1 << " " << z - b << endl;
            } else {
                cout << divx + divy << " " << 0 << endl;
            }
        } else {
            if(a + b >= z) {
                cout << divx + divy + 1 << " " << z - a << endl;
            } else {
                cout << divx + divy << " " << 0 << endl;
            }
        }
    }
}