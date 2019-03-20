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
    long long signed n;
    cin >> n;
    long long signed sum1 = 0, sum2 = 0;
    for(int i=0;i<2*n;i++) {
        long long signed num1, num2;
        cin >> num1 >> num2;
        sum1 += num1;
        sum2 += num2;
    }
    sum1 /= n;
    sum2 /= n;
    cout << sum1 << " " << sum2 << endl;
}