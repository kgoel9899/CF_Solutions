#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e18;
int32_t main() {
    int n;
    cin >> n;
    vector<string> v(n);
    for(int i=0;i<n;i++) {
        cin >> v[i];
    }
    vector<vector<int>> adj(26);
    vector<int> indeg(26);
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            int x = 0;
            while(x < min(v[i].size(), v[j].size()) && v[i][x] == v[j][x]) {
                x++;
            }
            if(x == min(v[i].size(), v[j].size())) {
                if(v[i].size() > v[j].size()) {
                    cout << "Impossible" << endl;
                    return 0;
                }
            } else {
                adj[v[i][x] - 'a'].push_back(v[j][x] - 'a');
                indeg[v[j][x] - 'a']++;
            }
        }
    }
    queue<int> q;
    for(int i=0;i<26;i++) {
		if(indeg[i] == 0) q.push(i);
	}
	vector<int> ans;
	while(!q.empty()) {
		int f = q.front();
		q.pop();
		ans.push_back(f);
		for(int i=0;i<adj[f].size();i++) {
			indeg[adj[f][i]]--;
			if(indeg[adj[f][i]] == 0) q.push(adj[f][i]);
		}
	}
    if(ans.size() != 26) cout << "Impossible" << endl;
    else {
        for(int i=0;i<26;i++) {
            cout << char('a' + ans[i]);
        }
        cout << endl;
    }
}