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
    int pos = 0, neg = 0, zero = 0;
    for(int i=0;i<n;i++) {
        int num;
        cin >> num;
        if(num > 0) {
            pos++;
        } else if (num < 0) {
            neg++;
        } else {
            zero++;
        }
    }
    int reqd = (n + 1) / 2;
    if(pos >= reqd) {
        cout << 1 << endl;
    } else {
        if(neg >= reqd) {
            cout << -1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
}