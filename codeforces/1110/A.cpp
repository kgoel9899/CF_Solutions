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
    int b, k;
    cin >> b >> k;
    int arr[k];
    int odd = 0, even = 0;
    for(int i=0;i<k;i++) {
        cin >> arr[i];
        if(arr[i] % 2 == 0){
            even++;
        } else {
            odd++;
        }
    }
    if(even == k) {
        cout << "even" << endl;
    } else if (b % 2 == 0) {
        if(arr[k - 1] % 2 == 0) {
            cout << "even" << endl;
        } else {
            cout << "odd" << endl;
        }
    } else if (odd % 2 == 0) {
        cout << "even" << endl;
    }
    else {
        cout << "odd" << endl;
    }
}
