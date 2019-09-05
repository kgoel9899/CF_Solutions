#include<bits/stdc++.h>
#include<iostream>
#define ll long long
#define MAX 100001
#define MOD 1000000007
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        ll str, intt, exp;
        cin >> str >> intt >> exp;
        if(str > intt) {
            ll temp = str - intt + 1;
            if(temp == exp) {
                cout << exp << endl;
            } else if(temp < exp) {
                ll y = (str + exp - intt + 1) / 2;
                ll x = exp - y;
                if((exp - x) < 0) {
                cout << 0 << endl;
                } else {
                    cout << exp - x << endl;
                }
            } else {
                if((temp - 1) == exp) {
                    cout << exp << endl;
                } else {
                    cout << exp + 1 << endl;
                }
            }
        } else if (str == intt) {
            if(exp % 2 == 0) {
                cout << exp / 2 << endl;
            } else {
                cout << exp / 2 + 1 << endl;
            }
        } else {
            ll y = (str + exp - intt + 1) / 2;
            ll x = exp - y;
            if((exp - x) < 0) {
                cout << 0 << endl;
            } else {
                cout << exp - x << endl;
            }
        }
    }
}
