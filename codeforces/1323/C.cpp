#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAX 1000005
using namespace std;

int main() {
    fast;
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    int op = 0, clo = 0, diff = 0, flag = 0;
    for(int i=0;i<n;i++) {
        if(s[i] == '(') {
            op++;
            diff++;
        } else {
            clo++;
            diff--;
        }
        if(diff < 0) {
            flag = 1;
            ans++;
        } else {
            if(flag == 1) {
                ans++;
            }
            flag = 0;
        }
    }
    if(clo != op) {
        cout << -1 << endl;
    } else 
    cout << ans << endl;
}