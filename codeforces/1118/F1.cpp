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
int ans = 0;
void dfs2(int** dp, int* arr, vector<int>* adj, int n, int ch, int par, int red, int blue) {
    for(int i=0;i<adj[ch].size();i++) {
        if(adj[ch][i] == par) {
            continue;
        }
        dfs2(dp, arr, adj, n, adj[ch][i], ch, red, blue);
    }
    if(dp[ch][0] == 0 && dp[ch][1] == blue) {
        ans++;
    }
    if(dp[ch][0] == red && dp[ch][1] == 0) {
        ans++;
    }
}
void dfs(int** dp, int* arr, vector<int>* adj, int n, int ch, int par) {
    if(arr[ch] == 1) {
        dp[ch][0]++;
    } else if (arr[ch] == 2) {
        dp[ch][1]++;
    }
    for(int i=0;i<adj[ch].size();i++) {
        if(adj[ch][i] == par) {
            continue;
        }
        dfs(dp, arr, adj, n, adj[ch][i], ch);
        dp[ch][0] += dp[adj[ch][i]][0];
        dp[ch][1] += dp[adj[ch][i]][1];
    }
}
int main() {
    fast;
    int n;
    cin >> n;
    int* arr = new int[n + 10];
    vector<int>* adj = new vector<int>[n + 10];
    int** dp = new int*[n + 1];
    for(int i=0;i<=n;i++) {
        dp[i] = new int[2];
        for(int j=0;j<2;j++) {
            dp[i][j] = 0;
        }
    }
    int red = 0, blue = 0;
    for(int i=1;i<=n;i++) {
        cin >> arr[i];
        if(arr[i] == 1) {
            red++;
        } else if (arr[i] == 2) {
            blue++;
        }
    }
    for(int i=0;i<n-1;i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(dp, arr, adj, n, 1, 0);
    dfs2(dp, arr, adj, n, 1, 0, red, blue);
    cout << ans << endl;
}
