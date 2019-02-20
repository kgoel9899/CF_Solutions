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
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int a = INT_MIN, b = INT_MIN;
    while(n--) {
        char c;
        cin >> c;
        if(c == '+') {
            int x, y;
            cin >> x >> y;
            a = max(a, min(x, y));
            b = max(b, max(x, y));
        } else {
            int h, w;
            cin >> h >> w;
            if((a <= h && b <= w) || (b <= h && a <= w)) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
}
