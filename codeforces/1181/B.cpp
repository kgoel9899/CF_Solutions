#include<iostream>
#include<iomanip>
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
#define MAX 200010
using namespace std;
string addd(string s1, string s2) {
    string s;
    int carry = 0;
    int n1 = (int)s1.length();
    int n2 = (int)s2.length();
    if(n1 < n2) {
        swap(s1, s2);
        swap(n1, n2);
    }
    int x = n1 - 1;
    for(int i=n2-1;i>=0;i--) {
        int num1 = s2[i] - '0';
        int num2 = s1[x] - '0';
        s.push_back(((num1 + num2 + carry) % 10) + '0');
        carry = (num1 + num2 + carry) / 10;
        x--;
    }
    for(;x>=0;x--) {
        s.push_back((((s1[x] - '0') + carry) % 10) + '0');
        carry = ((s1[x] - '0') + carry) / 10;
    }
    reverse(s.begin(), s.end());
    return s;
}
int main() {
    fast;
    int l;
    cin >> l;
    string s;
    cin >> s;
    if(l == 2) {
        if(s[1] == '0') {
            cout << stoi(s) << endl;
        } else {
            cout << min(stoi(s), (s[0] - '0') + (s[1] - '0')) << endl;
        }
        return 0;
    }
    string s1, s2, mini = s;
    for(int i=0;i<3;i++) {
       // cout << mini << endl;
        s1 = s.substr(0, l / 2 + i);
        s2 = s.substr(l / 2 + i);
        if(s2[0] == '0') {
            continue;
        }
        string temp = addd(s1, s2);
        if((int)temp.size() < (int)mini.size()) {
            mini = temp;
        } else if((int)temp.size() == (int)mini.size()){
            if(temp < mini) {
                mini = temp;
            }
        }
    }
    int i = l / 2;
    for(;i>=0;i--) {
        if(s[i] != '0') {
            break;
        }
    }
    s1 = s.substr(0, i);
    s2 = s.substr(i);
    string temp = addd(s1, s2);
    if((int)temp.size() < (int)mini.size()) {
        mini = temp;
    } else if((int)temp.size() == (int)mini.size()){
        if(temp < mini) {
            mini = temp;
        }
    }
    i = l / 2;
    for(;i<l;i++) {
        if(s[i] != '0') {
            break;
        }
    }
    s1 = s.substr(0, i);
    s2 = s.substr(i);
    temp = addd(s1, s2);
    if((int)temp.size() < (int)mini.size()) {
        mini = temp;
    } else if((int)temp.size() == (int)mini.size()){
        if(temp < mini) {
            mini = temp;
        }
    }
    cout << mini << endl;
}