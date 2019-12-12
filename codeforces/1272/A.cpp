#include<bits/stdc++.h>
#include<iostream>
#include<set>
#include<map>
#define ll unsigned long long int
#define ld long double
#define MAX 8200
#define MOD 1000000007
using namespace std;


int main() {
    int t;
    cin >> t;
    while(t--) {
        ll a, b, c;
        cin >> a >> b >> c;
        ll aa, bb, cc;
        aa = min(a, min(b, c));
        cc = max(a, max(b, c));
        if(aa == a) {
            if(cc == b) {
                bb = c;
            } else {
                bb = b;
            }
        } else if(aa == b) {
            if(cc == a) {
                bb = c;
            } else {
                bb = a;
            }
        } else {
            if(cc == a) {
                bb = b;
            } else {
                bb = a;
            }
        }
        ll mini = bb - aa + cc - bb + cc - aa;
        ll mini1 = mini - 2;
        ll mini2 = mini - 4;
        mini2 = max((ll)0, mini2);
        mini1 = max((ll)0, mini1);
        cout << min(mini1, min(mini, mini2)) << endl;
    }
}