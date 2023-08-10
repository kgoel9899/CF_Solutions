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

const int N = 300300;
const int A = 10;
char s[N];
char L[N], R[N];
int n, m;
int nxt[N][A];

void solve() {
	scanf("%s", s);
	n = strlen(s);
	scanf("%d", &m);
	scanf(" %s %s", L, R);
	for (int c = 0; c < A; c++)
		nxt[n][c] = n + 1;
	for (int i = n - 1; i >= 0; i--) {
		for (int c = 0; c < A; c++)
			nxt[i][c] = nxt[i + 1][c];
		nxt[i][(int)(s[i] - '0')] = i + 1;
	}
	int p = 0;
	for (int i = 0; i < m; i++) {
		int q = -1;
		for (int c = (int)(L[i] - '0'); c <= (int)(R[i] - '0'); c++)
			q = max(q, nxt[p][c]);
		if (q == n + 1) {
			printf("YES\n");
			return;
		}
		p = q;
	}
	printf("NO\n");
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		eprintf("--- Case #%d start ---\n", i);
		//printf("Case #%d: ", i);

		solve();

		//printf("%lld\n", (ll)solve());

		/*
		if (solve()) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
		*/

		eprintf("--- Case #%d end ---\n", i);
		eprintf("time = %.5lf\n", getCurrentTime());
		eprintf("++++++++++++++++++++\n");
	}


	return 0;
}
