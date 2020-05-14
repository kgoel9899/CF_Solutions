#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define w(x) int t; cin >> t; while(t--)
#define rep(i, a, b) for(int i = a; i <= b; i++)
#define repd(i, b, a) for(int i = b; i >= a; i--)
#define mk(arr,n,type) type* arr = new type[n];
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define um unordered_map
#define us unordered_set
#define pqm priority_queue<int>
#define pqmi priority_queue<int, vi, greater<int>>
#define lb(v, val) lower_bound(v.begin(), v.end(), val) - v.begin();
#define ub(v, val) upper_bound(v.begin(), v.end(), val) - v.begin();
#define setbits(x) __builtin_popcountll(x)
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define out(flag) flag ? cout << "NO" << endl : cout << "YES" << endl;
#define MAX 100001
#define mod 998244353
#define inf 1e18
#define PI 3.1415926535

void IO() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fast;
}

int val = 1;

int helper(vector<int>& v, int st, int end, int val) {
	if (st > end) return 0;
	int ind = (st + end) / 2;
	v[ind] = val;
	if (end - ind > ind - st) {
		int v1 = helper(v, ind + 1, end, val + 1);
		int v2 = helper(v, st, ind - 1, v1 + 1);
		return v2;
	} else {
		int v1 = helper(v, st, ind - 1, val + 1);
		int v2 = helper(v, ind + 1, end, v1 + 1);
		return v2;
	}
}


class compare {
public:
	bool operator() (pair<int, int> p1, pair<int, int> p2) {
		if (p1.first == p2.first) {
			return p1.second > p2.second;
		}
		return p1.first < p2.first;

	}
};

int main() {

	IO();

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> v(n);
		priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
		int st = 0, end = n - 1;
		int val = 2;
		int ind = (st + end) / 2;
		v[ind] = 1;
		pq.push(make_pair(ind - st, st));
		pq.push(make_pair(end - ind, ind + 1));
		while (!pq.empty() && val <= n) {
			pair<int, int> curr = pq.top();
			pq.pop();
			st = curr.second;
			end = st + curr.first - 1;
			ind = (st + end) / 2;
			v[ind] = val++;
			pq.push(make_pair(ind - st, st));
			pq.push(make_pair(end - ind, ind + 1));
		}
		for (int i = 0; i < n; i++) {
			cout << v[i] << " ";
		}
		cout << endl;
	}

	return 0;
}
