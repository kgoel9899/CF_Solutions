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
struct node {
    int l, r;
};
int main() {
    int n;
    cin >> n;
    node arr[n];
    for(int i=0;i<n;i++) {
        cin >> arr[i].l >> arr[i].r;
    }
    int k;
    cin >> k;
    for(int i=0;i<n;i++) {
        if(k >= arr[i].l && k <= arr[i].r) {
            cout << n - i << endl;
        }
    }
}
