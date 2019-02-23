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
    long long w1, h1, w2, h2;
    cin >> w1 >> h1 >> w2 >> h2;
    long long a1 = 2 + h1 + h2;
    long long a2 = w2 + 1;
    long long a3 = w1 + 1;
    long long a4 = h1;
    long long a5 = h2;
    long long a6 = abs(w1 - w2);
    cout << a1 + a2 + a3 + a4 + a5 + a6 << endl;
}