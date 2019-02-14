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
#define MAX 1000000
using namespace std;
int main() {
    int x, y, z, a, b, c;
    cin >> x >> y >> z;
    cin >> a >> b >> c;
    while(true) {
        if(x > a) {
            cout << "NO" << endl;
            break;
        }
        a -= x;
        if(y > (a + b)) {
            cout << "NO" << endl;
            break;
        }
        a -= y;
        if(z > (a + b + c)) {
            cout << "NO" << endl;
            break;
        }
        cout << "YES" << endl;
        break;
    }
}
