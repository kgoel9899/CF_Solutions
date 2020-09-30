#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
#define MOD 1000000007
#define int long long
#define ld long double
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
struct node {
	int sum, ssum;
};
void build(vector<node>& tree, vector<int>& v, vector<int>& a, int st, int end, int treeNode) {
	if(st == end) {
		tree[treeNode].sum = v[st];
		tree[treeNode].ssum = a[st];
		return;
	}
	int mid = (st + end) / 2;
	build(tree, v, a, st, mid, 2 * treeNode);
	build(tree, v, a, mid + 1, end, 2 * treeNode + 1);
	tree[treeNode].sum = tree[2 * treeNode].sum + tree[2 * treeNode + 1].sum;
	tree[treeNode].ssum = tree[2 * treeNode].ssum + tree[2 * treeNode + 1].ssum;
}
node query(vector<node>& tree, int st, int end, int treeNode, int l, int r) {
	node result;
	result.sum = 0;
	result.ssum = 0;
	if(st > r || end < l) return result;
	if(st >= l && end <= r) return tree[treeNode];
	int mid = (st + end) / 2;
	node ans1 = query(tree, st, mid, 2 * treeNode, l, r);
	node ans2 = query(tree, mid + 1, end, 2 * treeNode + 1, l, r);
	result.sum = ans1.sum + ans2.sum;
	result.ssum = ans1.ssum + ans2.ssum;
	return result;
}
int32_t main() {
	fast;
	int t = 1;
	// cin >> t;	
	while(t--) {
		int n;
		cin >> n;
		vector<int> v(n), a(n);
		for(int i=0;i<n;i++) {
			cin >> v[i];
			a[i] = v[i];
		}
		sort(a.begin(), a.end());
		vector<node> tree(4 * n);
		build(tree, v, a, 0, n - 1, 1);
		int m;
		cin >> m;
		while(m--) {
			int t, l, r;
			cin >> t >> l >> r;
			if(t == 1) cout << query(tree, 0, n - 1, 1, l - 1, r - 1).sum << endl;
			else cout << query(tree, 0, n - 1, 1, l - 1, r - 1).ssum << endl;
		}
	}
}