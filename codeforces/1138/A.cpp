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
    int current, ct = 0, longest = 0;
    vector<int> v;
    int num;
    cin >> num;
    current = num;
    ct++;
    for(int i=0;i<n-1;i++) {
        cin >> num;
        if(current != num) {
            v.push_back(ct);
            ct = 1;
        } else {
            ct++;
        }
        current = num;
    }
    v.push_back(ct);
    for(int i=0;i<v.size()-1;i++) {
        longest = max(longest, min(v[i], v[i + 1]));
    }
    cout << 2 * longest << endl;
}
