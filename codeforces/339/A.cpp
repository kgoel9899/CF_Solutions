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
        int n = s.size();
        vector<int> v;
        for(int i=0;i<n;i+=2) {
            v.push_back(s[i] - '0');
        }
        sort(v.begin(), v.end());
        for(int i=0;i<(int)v.size()-1;i++) {
            cout << v[i] << '+';
        }
        cout << v.back() << endl;
    }
}