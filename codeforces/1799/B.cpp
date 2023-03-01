#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <array>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) {fprintf(stderr, __VA_ARGS__);fflush(stderr);}
#else
	#define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

const int N = 10100;
int n, ansSz;
pii ans[N];
int a[N];

void solve() {
	ansSz = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int l = a[0], r = a[0];
	for (int i = 0; i < n; i++) {
		l = min(l, a[i]);
		r = max(r, a[i]);
	}
	if (l == r) {
		printf("0\n");
		return;
	}
	if (l == 1) {
		printf("-1\n");
		return;
	}
	while(true) {
		int p = 0, q = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] > a[p]) p = i;
			if (a[i] < a[q]) q = i;
		}
		if (a[p] == a[q]) break;
		assert(a[q] > 1);
		ans[ansSz++] = mp(p + 1, q + 1);
		a[p] = (a[p] + a[q] - 1) / a[q];
		assert(a[p] > 1);
	}
	printf("%d\n", ansSz);
	for (int i = 0; i < ansSz; i++)
		printf("%d %d\n", ans[i].first, ans[i].second);
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}
