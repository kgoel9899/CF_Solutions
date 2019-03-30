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
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int main() {
    fast;
    ll n;
    cin >> n;
    string s = to_string(n);
    ll ans = n, maxi;
    ll tempn = ans;
    ll prodd = 1;
    while(tempn) {
        prodd *= tempn % 10;
        tempn /= 10;
    }
    maxi = prodd;
    for(ll i=0;i<s.size();i++) {
        if(s[i] != '0') {
            string temp = s;
            temp[i] = ((s[i] - '0') - 1) + '0';
            for(ll j=i+1;j<temp.size();j++) {
                temp[j] = '9';
            }
            ll tempp = 0;
            for(ll k=0;k<s.size();k++) {
                tempp += (temp[k] - '0') * ((ll)pow(10, s.size() - k - 1));
            }
            ll temp1 = ans, temp2 = tempp;
            ll prod1 = 1, prod2 = 1;
            while(temp1) {
                prod1 *= temp1 % 10;
                temp1 /= 10;
            }
            while(temp2) {
                prod2 *= temp2 % 10;
                temp2 /= 10;
            }
            if(prod2 > prod1) {
                ans = tempp;
            }
            maxi = max(maxi, max(prod1, prod2));
        }
    }
    cout << maxi << endl;
}