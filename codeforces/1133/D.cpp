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
    int ans = 0;
    int temp = 0;
    long double a[n], b[n];
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    for(int i=0;i<n;i++) {
        cin >> b[i];
    }
    map<long double, int> m;
    for(int i=0;i<n;i++) {
        if(a[i] == 0) {
            if(b[i] == 0) {
                temp++;
            }
            continue;
        }
        long double d = b[i] / a[i];
        if(m.find(d) == m.end()) {
            m[d] = 1;
        } else {
            m[d] += 1;
        }
    }
    map<long double, int>::iterator it = m.begin();
    while(it != m.end()) {
        ans = max(ans, it->second);
        it++;
    }
    cout << ans + temp << endl;
}
