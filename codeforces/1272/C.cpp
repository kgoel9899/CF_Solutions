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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    string av;
    for(int i=0;i<k;i++) {
        char ch;
        cin >> ch;
        av += ch;
    }
    int curr = 0;
    ll tot = 0;
    ll ans = 0;
    int flag = 0;
    for(int i=0;i<n;i++) {
        flag = 0;
        for(int j=0;j<k;j++) {
            if(s[i] == av[j]) {
                tot++;
                flag = 1;
                break;
            }
        }
        if(flag == 0) {
            ans += (tot * (tot + (ll)1)) / ((ll)2);
            tot = 0;
        }
    }
    if(flag == 1) {
        ans += (tot * (tot + 1)) / 2;
    }
    cout << ans << endl;
}