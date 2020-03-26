#include<bits/stdc++.h>
#define MOD 998244353
#define ll long long
#define endl "\n"
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAX 1000005
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string s1 = "1", s2 = "1";
        int flag = 0;
        for(int i=1;i<n;i++) {
            if(s[i] == '2') {
                if(flag == 1) {
                    s1 += '0';
                    s2 += '2';
                } else {
                    s1 += '1';
                    s2 += '1';
                }
            } else if(s[i] == '1') { 
                if(flag == 1) {
                    s1 += '0';
                    s2 += '1';
                } else {
                    s1 += '1';
                    s2 += '0';
                }
                flag = 1;
            } else {
                s1 += '0';
                s2 += '0';
            }
        }
        for(int i=0;i<n;i++) {
            cout << s1[i] - '0';
        }
        cout << endl;
        for(int i=0;i<n;i++) {
            cout << s2[i] - '0';
        }
        cout << endl;
    }
}