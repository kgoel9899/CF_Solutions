#include<bits/stdc++.h>
#define ll long long int
#define MAX 8200
#define MOD 1000000000
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    int vis[n + 1] = {0};
    vector<int> v;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
        if(arr[i] != 0) vis[arr[i]] = 1;
    }
    for(int i=1;i<=n;i++) {
        if(vis[i] == 0) {
            v.push_back(i);
        }
    }
    int curr = v.size();
    int lastDone = -1;
    for(int i=0;i<n;i++) {
        if(arr[i] == 0) {
            if(v[curr - 1] == (i + 1)) {
                if(curr >= 2) {
                    arr[i] = v[curr - 2];
                    int temp = v[curr - 1];
                    v.pop_back();
                    v.pop_back();
                    v.push_back(temp);
                } else {
                    arr[i] = v[curr - 1];
                    int save = arr[i];
                    arr[i] = arr[lastDone];
                    arr[lastDone] = save;
                }
            } else {
                arr[i] = v[curr - 1];
                v.pop_back();
            }
            curr = v.size();
            lastDone = i;
        }
    }
    for(int i=0;i<n;i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}