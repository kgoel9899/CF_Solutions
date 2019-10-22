#include<bits/stdc++.h>
#include<iostream>
#include<set>
#include<map>
#define ll unsigned long long int
#define ld long double
#define MAX 8200
#define MOD 1000000007
using namespace std;
vector<int> temp;
void dfs(int p, int* arr, int* vis, int n) {
    if(vis[p]) {
        return;
    }
    vis[p] = 1;
    temp.push_back(p);
    dfs(arr[p], arr, vis, n);
}
 
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int arr[n + 1], vis[n + 1], ans[n + 1];
        for(int i=1;i<=n;i++) {
            cin >> arr[i];
            vis[i] = 0;
        }
        for(int i=1;i<=n;i++) {
            if(vis[i] == 0) {
                dfs(i, arr, vis, n);
                for(int j=0;j<temp.size();j++) {
                    ans[temp[j]] = temp.size();
                }
                temp.clear();
            }
        }
        for(int i=1;i<=n;i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}