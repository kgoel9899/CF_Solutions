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
    int y, b, r;
    cin >> y >> b >> r;
    int temp = min(y, min(b - 1, r - 2));
    cout << 3 * temp + 3 << endl;
}
