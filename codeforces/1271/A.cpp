#include<bits/stdc++.h>
#include<iostream>
#include<set>
#include<map>
#define ll long long int
#define ld long double
#define MAX 8200
#define MOD 1000000007
using namespace std;


int main() {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    ll ans = 0;
    ans += min(a, d) * e;
    int temp = min(a, d);
    a -= temp;
    d -= temp;
    int temp1 = min(b, min(c, d));
    ans += temp1 * f;
    a += temp;
    d += temp;
    ll ans1 = 0;
    temp1 = min(b, min(c, d));
    ans1 += temp1 * f;
    b -= temp1;
    c -= temp1;
    d -= temp1;
    temp = min(a, d);
    ans1 += temp * e;
    cout << max(ans, ans1) << endl;
}