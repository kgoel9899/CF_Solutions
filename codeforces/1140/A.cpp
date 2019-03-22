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
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int main() {
    IO;
    int n;
    cin >> n;
    int hint[n];
    for(int i=0;i<n;i++) {
        cin >> hint[i];
    }
    int totPages = 1;
    int maxi = 0, days = 0;
    while(totPages <= n) {
        maxi = max(maxi, hint[totPages - 1]);
        if(maxi == totPages) {
            days++;
        }
        totPages++;
    }
    cout << days << endl;
}
