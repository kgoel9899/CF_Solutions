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
bool cont(int startx, int starty, int n, int** temp) {
    if(startx < n && starty < n && startx >= 0 && starty >= 0 && temp[startx][starty] == 0) {
        return true;
    }
    return false;
}
void dfs(int startx, int starty, int** temp, int** visited, int r[4], int c[4], int n) {
    visited[startx][starty] = 1;
    for(int i=0;i<4;i++) {
        if(cont(startx + r[i], starty + c[i], n, temp)) {
            if(visited[startx + r[i]][starty + c[i]] == 0) {
                dfs(startx + r[i], starty + c[i], temp, visited, r, c, n);
            }
        }
    }
}
int main() {
    IO;
    int n, r1, c1, r2, c2;
    cin >> n >> r1 >> c1 >> r2 >> c2;
    int** temp = new int*[n];
    for(int i=0;i<n;i++) {
        temp[i] = new int[n];
    }
    int** visited = new int*[n];
    for(int i=0;i<n;i++) {
        visited[i] = new int[n];
        for(int j=0;j<n;j++) {
            visited[i][j] = 0;
        }
    }
    for(int i=0;i<n;i++) {
        string s;
        cin >> s;
        for(int j=0;j<n;j++) {
            if(s[j] == '0') {
                temp[i][j] = 0;
            } else {
                temp[i][j] = 1;
            }
        }
    }
    int r[4] = {0, 0, -1, 1};
    int c[4] = {1, -1, 0, 0};
    vector<pair<int, int>> v1;
    int flag = 0;
    dfs(r1 - 1, c1 - 1, temp, visited, r, c, n);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(visited[i][j] == 1) {
                if(i + 1 == r2 && j + 1 == c2) {
                    cout << 0 << endl;
                    flag = 1;
                    break;
                }
                pair<int, int> p(i + 1, j + 1);
                v1.push_back(p);
                visited[i][j] = 0;
            }
        }
    }
    if(flag == 0) {
        vector<pair<int, int>> v2;
        dfs(r2 - 1, c2 - 1, temp, visited, r, c, n);
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(visited[i][j] == 1) {
                    pair<int, int> p(i + 1, j + 1);
                    v2.push_back(p);
                    visited[i][j] = 0;
                }
            }
        }
        int mini = INT_MAX;
        for(int i=0;i<v1.size();i++) {
            for(int j=0;j<v2.size();j++) {
                int dist = (int)pow((v2[j].first - v1[i].first), 2) + (int)pow((v2[j].second - v1[i].second), 2);
                mini = min(dist, mini);
            }
        }
        cout << mini << endl;
    }
    for(int i=0;i<n;i++) {
        delete [] temp[i];
    }
    delete [] temp;
}