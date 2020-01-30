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
        int n;
        cin >> n;
        if(n % 2 == 0) {
            for(int i=0;i<n/2;i++) {
                cout << 1;
            }
            cout << endl;
        } else {
            cout << 7;
            n -= 3;
            for(int i=0;i<n/2;i++) {
                cout << 1;
            }
            cout << endl;
        }
    }
}