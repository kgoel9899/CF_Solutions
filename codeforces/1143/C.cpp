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
    int n, flag = 0;;
    cin >> n;
    vector<int>* adj = new vector<int>[n + 1];
    int* par = new int[n + 1];
    int* res = new int[n + 1];
    int* rem = new int[n + 1];
    for(int i=0;i<n;i++) {
        int p, c;
        cin >> p >> c;
        par[i + 1] = p;
        res[i + 1] = c;
        if(p != -1) {
            adj[p].push_back(i + 1);
        }
    }
    for(int i=0;i<=n;i++) {
        rem[i] = 0;
    }
    for(int i=1;i<=n;i++) {
        if(res[i] == 1 && rem[i] == 0) {
            int ct = 0;
            for(int j=0;j<adj[i].size();j++) {
                if(res[adj[i][j]] == 1) {
                    ct++;
                }
            }
            if(ct == adj[i].size()) {
                rem[i] = 1;
                flag = 1;
                cout << i << " ";
            }
        }
    }
    if(flag == 0) {
        cout << -1 << endl;
    }
}