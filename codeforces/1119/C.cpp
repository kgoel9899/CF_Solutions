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
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAX 1010
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    int a[n][m], b[n][m];
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> a[i][j];
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> b[i][j];
        }
    }
    int flag1 = 0, flag2 = 0, flag3 = 0, ct1 = 0, ct2 = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(a[i][j] != b[i][j]) {
                flag1 = flag2 = ct1 = ct2 = 0;
                for(int k=i+1;k<n;k++) {
                    ct1++;
                    if(a[k][j] != b[k][j]) {
                        flag1 = 1;
                        a[k][j] = !a[k][j];
                        break;
                    }
                }
                if(flag1 == 0) {
                    break;
                }
                for(int l=j+1;l<m;l++) {
                    ct2++;
                    if(a[i][l] != b[i][l]) {
                        flag2 = 1;
                        a[i][l] = !a[i][l];
                        break;
                    }
                }
                if(flag2 == 0) {
                    break;
                }
                a[i][j] = !a[i][j];
                a[i + ct1][j + ct2] = !a[i + ct1][j + ct2];
            }
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(a[i][j] == b[i][j]) {
                continue;
            } else {
                flag3 = 1;
                cout << "No" << endl;
                break;
            }
        }
        if(flag3 == 1) {
            break;
        }
    }
    if(flag3 == 0) {
        cout << "Yes" << endl;
    }
}