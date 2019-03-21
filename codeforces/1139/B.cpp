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
    long long n;
    cin >> n;
    long long arr[n], ct = 0;
    for(long long i=0;i<n;i++) {
        cin >> arr[i];
    }
    ct += arr[n - 1];
    long long added = arr[n - 1];
    for(long long i=n-2;i>=0;i--) {
        if(added - 1 >= arr[i]) {
            ct += arr[i];
            added = arr[i];
        } else {
            if(added - 1 <= 0) {
                break;
            }
            ct += added - 1;
            added = added - 1;
      
        }
    }
    cout << ct << endl;
}
