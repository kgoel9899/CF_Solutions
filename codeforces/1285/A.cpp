#include<bits/stdc++.h>
#include<iostream>
#include<set>
#include<map>
#define ll long long int
#define ld long double
#define MAX 8200
#define MOD 1000000000
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int c1 = 0, c2 = 0;
    for(int i=0;i<n;i++) {
        if(s[i] == 'L') {
            c1++;
        } else {
            c2++;
        }
    }
    cout << c1 + c2 + 1 << endl;
}