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
    ll n, x, y;
    cin >> n >> x >> y;
    ll xc[n], yc[n];
    ll tc = 0, bc = 0, lc = 0, rc = 0;
    ll ansx = -1, ansy = -1, ans = -1;
    for(ll i=0;i<n;i++) {
        cin >> xc[i] >> yc[i];
    }
    if(x > 0) {
        for(ll i=0;i<n;i++) {
            if(xc[i] < x) {
                lc++;
            }
        }
        ans = lc;
        ansx = x - 1;
        ansy = y;
    }
    if(x < MOD) {
        for(ll i=0;i<n;i++) {
            if(xc[i] > x) {
                rc++;
            }
        }
        if(rc > ans) {
            ans = rc;
            ansx = x + 1;
            ansy = y;
        }
    }
    if(y < MOD) {
        for(ll i=0;i<n;i++) {
            if(yc[i] > y) {
                tc++;
            }
        }
        if(tc > ans) {
            ans = tc;
            ansx = x;
            ansy = y + 1;
        }
    }
    if(y > 0) {
        for(ll i=0;i<n;i++) {
            if(yc[i] < y) {
                bc++;
            }
        }
        if(bc > ans) {
            ans = bc;
            ansx = x;
            ansy = y - 1;
        }
    }
    cout << ans << endl;
    cout << ansx << " " << ansy << endl;
}