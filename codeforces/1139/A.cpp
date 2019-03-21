#include<iostream>
#include<cstring>
#include<iomanip>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<algorithm>
#include<sstream>
#include<unordered_set>
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    long long ct = 0;
    for(int i=0;i<n;i++) {
        if((s[i] - '0') % 2 == 0) {
            ct += i + 1;
        }
    }
    cout << ct << endl;
}