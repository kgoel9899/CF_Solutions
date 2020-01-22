#include<bits/stdc++.h>
#include<iostream>
#include<set>
#include<map>
#define ll long long int
#define ld long double
#define MAX 8200
#define MOD 1000000000
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        ll a, b, c, n;
        cin >> a >> b >> c >> n;
        ll temp = (n + a + b + c) / 3;
        if(temp * 3 == (n + a + b + c) && temp >= max(a, max(b, c))) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}