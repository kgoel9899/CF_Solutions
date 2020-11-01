#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e18;
const int N = 1e6 + 5;
int32_t main() {
    int t = 1;
    cin >> t;
    vector<int> sieve(N, 1);
    sieve[0] = 0;
    sieve[1] = 0;
    for(int i=2;i*i<=N;i++) {
        if(sieve[i] == 1) {
            for(int j=i*i;j<N;j+=i) {
                sieve[j] = 0;
            }
        }
    }
    while(t--) {
        int p, q;
        cin >> p >> q;
        if(p < q) cout << p << endl;
        else if(p == q) {
            int ans = 1;
            for(int i=1;i<=sqrt(p)+2;i++) {
                if(p % i == 0) {
                    if(i % q != 0) ans = max(ans, i);
                    int temp = p / i;
                    if(p % temp == 0) {
                        if(temp % q != 0) ans = max(ans, temp);
                    }
                }
            }
            cout << ans << endl;
        } else {
            int temp = __gcd(p, q);
            // cout << temp << endl;
            // return 0;
            if(q != temp) cout << p << endl;
            else {
                map<int, int> m;
                int qq = q;
                // return 0;
                for(int i=2;i<=sqrt(qq)+2;i++) {
                    assert(i < N);
                    if(sieve[i] == 1) {
                        int ct = 0;
                        while(q % i == 0) {
                            q /= i;
                            ct++;
                        }
                        if(ct != 0) m[i] = ct;
                        // int ni = q / i;
                        // cout << ni << endl;
                        // assert(ni < N);
                        // if(ct != 0 && ni < N && sieve[ni] == 1) {
                        //     ct = 0;
                        //     // if(q == 0)
                        //     while(q % ni == 0) {
                        //         q /= ni;
                        //         ct++;
                        //     }
                        //     if(ct != 0) m[ni] = ct;
                        // }
                    }
                }
                // cout << q << endl;
                // if(q == qq) {
                //     cout << p << endl;
                //     continue;
                // }
                if(q >= N || sieve[q] == 1) m[q] = 1;
                q = qq;
                map<int, int> m1;
                int pp = p;
                for(auto i : m) {
                    int pr = i.first;
                    int ct = 0;
                    // if(p == 0) break;
                    while(p % pr == 0) {
                        ct++;
                        p /= pr;
                    }
                    if(ct != 0) m1[pr] = ct;
                }
                map<int, int>::iterator it = m.begin(), it1 = m1.begin();
                int save = 0;
                int ans = 0;
                while(it != m.end()) {
                    save = it->first;
                    ans = max(ans, pp / (int)pow(it->first, it1->second - it->second + 1));
                    it++;
                    it1++;
                }
                if(save == 0) cout << p << endl;
                else cout << ans << endl;
            }
        }
    }
}