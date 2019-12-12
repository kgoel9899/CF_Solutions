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
        string s;
        cin >> s;
        int l = 0, r = 0, u = 0, d = 0;
        for(int i=0;i<(int)s.size();i++) {
            if(s[i] == 'L') {
                l++;
            } else if(s[i] == 'R') {
                r++;
            } else if(s[i] == 'U') {
                u++;
            } else {
                d++;
            }
        }
        int newlr = min(l, r);
        int newud = min(u, d);
        string ans = "";
        if(newlr == 0 && newud == 0) {
            cout << 0 << endl;
            cout << ans << endl;
            continue;
        } else {
            if(newlr == 0) {
                ans = "UD";
                cout << 2 << endl;
                cout << ans << endl;
                continue;
            } else if(newud == 0) {
                ans = "LR";
                cout << 2 << endl;
                cout << ans << endl;
                continue;
            } else {
                int ct = 0;
                for(int i=0;i<newud;i++) {
                    ans += 'U';
                    ct++;
                }
                for(int i=0;i<newlr;i++) {
                    ans += 'R';
                    ct++;
                } 
                for(int i=0;i<newud;i++) {
                    ans += 'D';
                    ct++;
                }
                for(int i=0;i<newlr;i++) {
                    ans += 'L';
                    ct++;
                }
                cout << ct << endl;
                cout << ans << endl;
                continue;
            }
        }
    }
}