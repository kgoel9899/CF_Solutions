#include <bits/stdc++.h>

using namespace std;

int n;

int needRep(const vector<int> &cnt, const vector<int> &need) {
	int res = 0;
	for (int i = 0; i < 3; ++i) {
		res += abs(cnt[i] - need[i]);
	}
	assert(res % 2 == 0);
	return res / 2;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	string s;
	cin >> n >> s;
	
	vector<int> cnt(3), cur(3, n / 3);
	for (auto c : s) {
		++cnt[c - '0'];
	}
	
	int need = needRep(cnt, cur);
		
	int curRep = 0;
	for (int i = 0; i < n; ++i) {
		--cnt[s[i] - '0'];
		for (int j = 0; j < 3; ++j) {
			if (cur[j] == 0) continue;
			int rep = j != s[i] - '0';
			--cur[j];
			if (curRep + rep + needRep(cnt, cur) == need) {
				s[i] = j + '0';
				curRep += rep;
				break;
			}
			++cur[j];
		}
	}
	
	cout << s << endl;
	
	return 0;
}