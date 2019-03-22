#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<algorithm>
#include<unordered_set>
#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int main() {
    ll n;
    cin >> n;
    if(n == 3) {
        cout << 6 << endl;
    } else if (n == 4) {
        cout << 18 << endl;
    } else {
        ll tot = 6 + n * (n - 1);
        for(ll i=3;i<n-1;i++) {
            tot += i * (i + 1);
        }
        cout << tot << endl;
    }
}