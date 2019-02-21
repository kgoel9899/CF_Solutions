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
#define MAX 100000
using namespace std;
int main() {
    int v, e;
    cin >> v >> e;
    vector<int>* edges = new vector<int>[v];
    int* visited = new int[v];
    for(int i=0;i<v;i++) {
        visited[i] = 0;
    }
    for(int i=0;i<e;i++) {
        int a, b;
        cin >> a >> b;
        edges[a - 1].push_back(b - 1);
        edges[b - 1].push_back(a - 1);
    }
    priority_queue<int, vector<int>, greater<int>> pending;
    pending.push(0);
    visited[0] = 1;
    while(!pending.empty()) {
        int current = pending.top();
        pending.pop();
        cout << current + 1 << " ";
        for(int i=0;i<edges[current].size();i++) {
            if(visited[edges[current][i]] == 0) {
                pending.push(edges[current][i]);
                visited[edges[current][i]] = 1;
            }
        }
    }
}