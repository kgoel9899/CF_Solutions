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
    int arr[n];
    int mini = 500, totsumm = 0, tempsumm = 0, minsumm;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
        mini = min(arr[i], mini);
        totsumm += arr[i];
    }
    minsumm = totsumm;
    for(int i=0;i<n;i++) {
        for(int j=2;j<=arr[i];j++) {
            if(!(arr[i] % j)) {
                tempsumm = totsumm - arr[i] - mini + arr[i] / j + mini * j;
                minsumm = min(minsumm, tempsumm);
            }
        }
    }
    cout << minsumm << endl;
}