#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
#define MOD 1000000007
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
int main() {
	fast;
	int t = 1;
	cin >> t;
    while(t--) {
		int n;
		cin >> n;
		vector<int> v(n), lock(n);
		for(int i=0;i<n;i++) {
			cin >> v[i];
		}
		for(int i=0;i<n;i++) {
			cin >> lock[i];
		}
		vector<int> temp;
		for(int i=0;i<n;i++) {
			if(lock[i] == 0) temp.push_back(v[i]);
		}
		sort(temp.begin(), temp.end(), greater<int>());
		int x = 0;
		for(int i=0;i<n;i++) {
			if(lock[i] == 0) v[i] = temp[x++];
		}
		for(int i=0;i<n;i++) {
			cout << v[i] << " ";
		}
		cout << endl;
    }
}
