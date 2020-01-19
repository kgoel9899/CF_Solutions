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
    cout << std::fixed;
    cout << std::setprecision(12);
    float ans = 0;
    for(int i=n;i>=1;i--) {
        ans += 1.0 / i;
    }
    cout << ans << endl;
}