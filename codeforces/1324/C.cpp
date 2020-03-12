#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAX 1000005
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int maxi = -1;
        int n = (int)s.size();
        int ct = 1;
        for(int i=0;i<n;i++) {
            if(s[i] == 'R') {
                maxi = max(maxi, ct);
                ct = 1;
            } else {
                ct++;
            }
        }
        maxi = max(maxi, ct);
        cout << maxi << endl;
    }
}