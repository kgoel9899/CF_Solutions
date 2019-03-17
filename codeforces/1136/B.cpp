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
    int n, k;
    cin >> n >> k;
    int check = n / 2;
    long long total = 0;
    if(k > check) {
        k = n - k + 1;
    }
    if(k == 1) {
        total += 2 * n + n - 1 + 1;
    } else if (k == 2) {
        total += 2 * n + n + 1;
    } else {
        total += 2 * n + n - 1 + k - 1 + 1;
    }
    cout << total << endl;
}
