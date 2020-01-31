#include<bits/stdc++.h>
#define ll long long int
#define MAX 8200
#define MOD 1000000000
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int maxi = INT_MIN;
        int i = 0;
        int ct = 0;
        for(i=0;i<n;i++) {
            if(s[i] == 'A') {
                break;
            }
        }
        int prev = 0;
        for(;i<n;i++) {
            if(s[i] == 'A') {
                maxi = max(maxi, ct);
                ct = 0;
            } else {
                ct++;
            }
        }
        maxi = max(maxi, ct);
        cout << maxi << endl;
    }
}