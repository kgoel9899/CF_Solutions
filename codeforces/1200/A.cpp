#include<iostream>
#include<iomanip>
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
#define MAX 200010
using namespace std;
int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans[10];
    for(int i=0;i<10;i++) {
        ans[i] = 0;
    }
    for(int i=0;i<(int)s.size();i++) {
        if(s[i] == 'L') {
            for(int j=0;j<10;j++) {
                if(ans[j] == 0) {
                    ans[j] = 1;
                    break;
                }
            }
        } else if(s[i] == 'R') {
            for(int j=9;j>=0;j--) {
                if(ans[j] == 0) {
                    ans[j] = 1;
                    break;
                }
            }
        } else {
            ans[s[i] - '0'] = 0;
        }
    }
    for(int i=0;i<10;i++) {
        cout << ans[i];
    }
    cout << endl;
}