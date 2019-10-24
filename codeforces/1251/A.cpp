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
        map<char, int> m;
        for(int i=97;i<97+26;i++) {
            m[i] = -1;
        }
        int n = s.size();
        char curr = s[0];
        int currlen = 1;
        for(int i=1;i<n;i++) {
            if(s[i] == curr) {
                currlen++;
            } else {
                if(currlen % 2 == 1) {
                    m[s[i - 1]] = 1;
                }
                curr = s[i];
                currlen = 1;
            }
        }
        if(currlen % 2 == 1) {
            m[s[n - 1]] = 1;
        }
        map<char, int>::iterator it = m.begin();
        string ans = "";
        while(it != m.end()) {
            if(it->second == 1) {
                ans += it->first;
            }
            it++;
        }
        cout << ans << endl;
    }
}