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
        ll n, x;
        cin >> n >> x;
        string s;
        cin >> s;
        ll arr[n];
        ll ct = 0;
        arr[0] = (s[0] == '0') ? 1 : -1;
        if(arr[0] == x) {
            ct++;
        }
        for(int i=1;i<n;i++) {
            arr[i] = (s[i] == '0') ? 1 : -1;
            arr[i] += arr[i - 1];
            if(arr[i] == x) {
                ct++;
            }
        }
        ll last = arr[n - 1];
        ct = (x == 0) ? 1 : 0;
        // cout << last << endl;
        if(last == 0) {
            int i = 0;
            for(;i<n;i++) {
                if(arr[i] == x) {
                    cout << -1 << endl;
                    break;
                }
            }
            if(i == n) {
                cout << 0 << endl;
            }
        } else {
            for(int i=0;i<n;i++) {
                if((last < 0 && arr[i] < x) || (last > 0 && arr[i] > x)) {
                    continue;
                }
                if((x - arr[i]) % last == 0) {
                    ct++;
                } 
            }
            cout << ct << endl;
        }
    }
}