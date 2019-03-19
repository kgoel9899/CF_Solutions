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
    long long n, m;
    cin >> n >> m;
    int ct = 0;
    if(n == m) {
        cout << 0 << endl;
    } else {
        if(m % n == 0) {
            long long temp = m / n;
            while(temp % 2 == 0) {
                ct++;
                temp /= 2;
            }
            while(temp % 3 == 0) {
                ct++;
                temp /= 3;
            }
            if(temp == 1) {
                cout << ct << endl;
            } else {
                cout << -1 << endl;
            }
        } else {
            cout << -1 << endl;
        }
    }
}
