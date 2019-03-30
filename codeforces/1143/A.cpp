#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<algorithm>
#include<unordered_set>
#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int main() {
    fast;
    int n;
    cin >> n;
    int arr[n];
    int zero = 0, one = 0;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
        if(arr[i] == 0) {
            zero++;
        } else {
            one++;
        }
    }
    int x = 0, y = 0;
    for(int i=0;i<n;i++) {
        if(x == zero) {
            cout << i << endl;
            break;
        }
        if(y == one) {
            cout << i << endl;
            break;
        }
        if(arr[i] == 0) {
            x++;
        } else {
            y++;
        }
    }
}