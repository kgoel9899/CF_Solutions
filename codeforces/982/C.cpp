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
void dfs(int* dp, vector<int>* adj, int n, int ch, int par) {
    dp[ch] = 1;
    for(int i=0;i<adj[ch].size();i++) {
        if(adj[ch][i] == par) {
            continue;
        }
        dfs(dp, adj, n, adj[ch][i], ch);
        dp[ch] += dp[adj[ch][i]];
    }
}
int main() {
    fast;
    int n, ans = 0;
    cin >> n;
    vector<int>* adj = new vector<int>[n + 1];
    for(int i=0;i<n-1;i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int* dp = new int[n + 1];
    for(int i=0;i<=n;i++) {
        dp[i] = 0;
    }
    if(n % 2 == 1) {
        cout << -1 << endl;
        return 0;
    }
    dfs(dp, adj, n, 1, 0);
    for(int i=0;i<=n;i++) {
        if(dp[i] % 2 == 0 && dp[i] > 0) {
            ans++;
        }
    }
    cout << ans - 1 << endl;
}
//?????????????????