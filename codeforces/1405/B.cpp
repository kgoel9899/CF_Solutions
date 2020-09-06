#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
#define MOD 1000000007
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
void IO() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fast;
}
int main() {
	IO();
	ll t = 1;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		vector<ll> v(n);
		queue<ll> pos, neg, neg1;
		for (ll i = 0; i < n; i++) {
			cin >> v[i];
			if (v[i] > 0) pos.push(i);
			else {
				neg.push(i);
				neg1.push(i);
			}
		}
		ll ans = 0;
		for (ll i = 0; i < n; i++) {
			if (v[i] > 0) {
				if (neg1.size() != 0) {
					while (!neg1.empty() && neg1.front() < i) {
						neg1.pop();
					}
					if (neg1.size() == 0) break;
					// cout << neg1.front() << endl;
					if (v[i] < abs(v[neg1.front()])) {
						v[neg1.front()] += v[i];
						v[i] = 0;
					} else if (v[i] > abs(v[neg1.front()])) {
						while (!neg1.empty() && v[i] >= abs(v[neg1.front()])) {
							v[i] += v[neg1.front()];
							v[neg1.front()] = 0;
							neg1.pop();
						}
						if (v[i] != 0 && neg1.size() != 0) {
							// cout << neg1.size() << endl;
							v[neg1.front()] += v[i];
							if (v[neg1.front()] == 0) neg1.pop();
							v[i] = 0;
						}
					} else {
						v[i] = 0;
						v[neg1.front()] = 0;
						neg1.pop();
					}
				}
			}
		}
		// for (int i = 0; i < n; i++) {
		// 	cout << v[i] << " ";
		// }
		// cout << endl;
		for (ll i = 0; i < n; i++) {
			if (v[i] < 0) {
				// cout << neg.front() << endl;
				neg.pop();
				if (abs(v[i]) < v[pos.front()]) {
					ans += abs(v[i]);
					v[pos.front()] += v[i];
					v[i] = 0;
				} else if (abs(v[i]) > v[pos.front()]) {
					// cout << i << endl;
					while (!pos.empty() && abs(v[i]) >= v[pos.front()]) {
						ans += v[pos.front()];
						v[i] += v[pos.front()];
						v[pos.front()] = 0;
						pos.pop();
						// cout << ans << endl;
					}
					if (v[i] != 0) {
						ans += abs(v[i]);
						v[pos.front()] -= abs(v[i]);
						// cout << pos.front() << " " << v[pos.front()] << endl;
						// for (int j = 0; j < n; j++) {
						// 	cout << v[j] << " ";
						// }
						// cout << endl;
						if (v[pos.front()] == 0) pos.pop();
						v[i] = 0;
					}
				} else {
					ans += abs(v[i]);
					v[i] = 0;
					v[pos.front()] = 0;
					pos.pop();
				}
			} else if (v[i] > 0) {
				pos.pop();
				if (v[i] < abs(v[neg.front()])) {
					v[neg.front()] += v[i];
					v[i] = 0;
				}
				else if (v[i] > abs(v[neg.front()])) {
					while (!neg.empty() && v[i] >= abs(v[neg.front()])) {
						v[i] += v[neg.front()];
						v[neg.front()] = 0;
						neg.pop();
					}
					if (v[i] != 0 && neg.size() != 0) {
						v[neg.front()] += v[i];
						if (v[neg.front()] == 0) neg.pop();
						v[i] = 0;
					}
				} else {
					v[i] = 0;
					v[neg.front()] = 0;
					neg.pop();
				}
			}
			// for (int j = 0; j < n; j++) {
			// 	cout << v[i] << " ";
			// }
			// cout << endl;
		}
		cout << ans << endl;
	}
}
