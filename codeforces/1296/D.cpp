#include<bits/stdc++.h>
#define ll long long int
#define MAX 8200
#define MOD 1000000000
using namespace std;

int main() {
    ll n, a, b, k;
    cin >> n >> a >> b >> k;
    ll arr[n];
    ll ct = 0;
    vector<ll> v;
    for(ll i=0;i<n;i++) {
        cin >> arr[i];
        if(arr[i] % (a + b) == 0) {
            ll temp = arr[i];
            temp -= (a + b) * ((temp - 1) / (a + b));
            ll temp1 = temp % a, temp2 = temp / a;
            if(temp1 == 0) {
                temp2--;
            }
            if(k >= temp2) {
                v.push_back(temp2);
            }
        } else {
            ll temp = arr[i];
            temp -= (a + b) * (temp / (a + b));
            if(temp - a > 0) {
                ll temp1 = temp % a, temp2 = temp / a;
                if(temp1 == 0) {
                    temp2--;
                }
                if(k >= temp2) {
                    v.push_back(temp2);
                }
            } else {
                ct++;
            }
        }
    }
    sort(v.begin(), v.end());
    for(ll i=0;i<v.size();i++) {
        k -= v[i];
        if(k >= 0) {
            ct++;
        }
    }
    cout << ct << endl;
}