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
    int q;
    cin >> q;
    while(q--) {
        long long l, r, d;
        cin >> l >> r >> d;
        if(d < l) {
            cout << d << endl;
        } else {
            if(r % d == 0) {
                cout << (r / d + 1) * d << endl;
            } else {
                cout << (int)(ceil(r / (double)d)) * d << endl;
            }
        }
    }
}