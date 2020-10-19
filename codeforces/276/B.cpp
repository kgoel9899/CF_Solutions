#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
#define MOD 1000000007
#define int long long
#define ld long double
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--) {
        string s;
        cin >> s;
        map<char, int> m;
        for(auto i : s) {
            m[i]++;
        }
        int ct = 0;
        for(auto i : m) {
            if(i.second % 2 == 1) ct++;
        }
        if(ct <= 1) cout << "First" << endl;
        else {
            if(ct % 2 == 0) cout << "Second" << endl;
            else cout << "First" << endl;
        }
    }
}