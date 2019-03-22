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
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int main() {
    IO;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int lb = 0, rb = 0;
        for(int i=0;i<n;i++) {
            if(s[i] == '>') {
                rb = i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--) {
            if(s[i] == '<') {
                lb = n - i - 1;
                break;
            }
        }
        cout << min(lb, rb) << endl;
    }
}