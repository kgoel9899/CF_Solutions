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
    int num, arr[2 * n];
    for(int i=0;i<n;i++) {
        cin >> num;
        arr[i] = num;
        arr[n + i] = num;
    }
    int cont = 0, maxi = 0;
    for(int i=0;i<2*n;i++) {
        if(arr[i] == 1) {
            cont++;
        } else {
            maxi = max(maxi, cont);
            cont = 0;
        }
    }
    cout << maxi << endl;
}
