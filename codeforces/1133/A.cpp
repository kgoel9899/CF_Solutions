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
    string s1, s2, s3;
    cin >> s1 >> s2;
    int m1, h1, m2, h2, m3, h3, diff;
    h1 = (s1[0] - '0') * 10 + (s1[1] - '0');
    m1 = (s1[3] - '0') * 10 + (s1[4] - '0');
    h2 = (s2[0] - '0') * 10 + (s2[1] - '0');
    m2 = (s2[3] - '0') * 10 + (s2[4] - '0');
    if(m2 < m1) {
        diff = (h2 - h1) * 60 - abs(m2 - m1);
    } else {
        diff = (h2 - h1) * 60 + abs(m2 - m1);
    }
    m3 = m1 + diff / 2;
    h3 = h1;
    while(m3 >= 60) {
        m3 -= 60;
        h3++;
    }
    if(h3 < 10) {
        s3 += '0' + to_string(h3);
    } else {
        s3 += to_string(h3);
    }
    s3 += ':';
    if(m3 < 10) {
        s3 += '0' + to_string(m3);
    } else {
        s3 += to_string(m3);
    }
    cout << s3 << endl;
}
