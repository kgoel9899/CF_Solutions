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
        long long int n, a, b;
        cin >> n >> a >> b;
        long long int ans1 = n * a;
        long long int ans2 = (n / 2) * b + (n % 2) * a;
        cout << min(ans1, ans2) << endl;
    }
}