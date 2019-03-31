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
    int n;
    cin >> n;
    while(n--) {
        int flag = 0;
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        for(int i=1;i<s.size();i++) {
            if(s[i] - s[i - 1] != 1) {
                flag = 1;
                break;
            }
        }
        if(flag == 0) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}