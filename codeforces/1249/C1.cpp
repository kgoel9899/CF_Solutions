#include<bits/stdc++.h>
#include<iostream>
#include<set>
#include<map>
#define ll unsigned long long int
#define ld long double
#define MAX 8200
#define MOD 1000000007
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector<int> v;
        ll temp = n;
        while(temp) {
            int rem = temp % 3;
            v.push_back(rem);
            temp /= 3;
        }
        reverse(v.begin(), v.end());
        int flag = 0;
        int zero = -1;
        for(int i=0;i<(int)v.size();i++) {
            if(v[i] == 2) {
                flag = 1;
                v[i] = 0;
            }
            if(flag == 0 && v[i] == 0) {
                zero = i;
            }
        }
        if(flag == 1) {
            if(zero == -1) {
                int i = (int)v.size();
                ll finans = 1;
                while(i >= 1) {
                    finans *= 3;
                    i--;
                }
                cout << finans << endl;
            } else {
                for(int i=zero;i<v.size();i++) {
                    v[i] = 0;
                }
                ll finans = 0;
                int y = 0;
                v[zero] = 1;
                for(int i=(int)v.size()-1;i>=0;i--) {
                    ll temp = 1;
                    int j = y;
                    while(j >= 1) {
                        temp *= 3;
                        j--;
                    }
                    finans += (ll)v[i] * temp;
                    y++;
                }
                cout << finans << endl;
            }
        } else {
            cout << n << endl;
        }
    }
}