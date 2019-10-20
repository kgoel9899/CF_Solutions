#include<bits/stdc++.h>
#include<iostream>
#include<set>
#include<map>
#define ll long long
#define MAX 8200
#define MOD 1000000007
using namespace std;

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll ne = 0, no = 0;
        for(ll i=0;i<n;i++) {
            ll num;
            cin >> num;
            if(num % 2 == 0) {
                ne++;
            } else {
                no++;
            }
        }
        ll m;
        cin >> m;
        ll me = 0, mo = 0;
        for(ll i=0;i<m;i++) {
            ll num;
            cin >> num;
            if(num % 2 == 0) {
                me++;
            } else {
                mo++;
            }
        }
        ll ans = ne * me + no * mo;
        cout << ans << endl;
    }
}