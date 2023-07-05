#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e6;
 
int main()
{
    int cases;
    scanf("%d", &cases);
    
    while (cases--) {
    	int n;
    	scanf ("%d", &n);
    	
    	vector <int> cnt(n + 1);
    	for (int i = 0; i < n; i++) {
    		int d;
    		scanf("%d", &d);
    		if (d < n) {
        		cnt[d]++;
    		} else {
    		    cnt[n] = N;
    		}
    	}
    	
    	bool good = true;
    	for (int i = 1; i <= n; i++) if (cnt[i] > cnt[i-1]) {
    	    good = false;
    	    break;
    	}
    	
    	puts(good ? "YES" : "NO");
    }
}