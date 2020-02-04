#include<bits/stdc++.h>
#define ll long long int
#define MAX 8200
#define MOD 1000000000
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        map<pair<int, int>, vector<int>> m;
        int n;
        cin >> n;
        string s;
        cin >> s;
        int finx = 0, finy = 0;
        pair<int, int> p1;
        int mini = INT_MAX;
        int l = -1, r = -1;
        p1.first = 0;
        p1.second = 0;
        m[p1] = {1};
        set<pair<int, int>> st;
        for(int i=0;i<n;i++) {
            if(s[i] == 'L') {
                finx--;
                p1.first = finx;
                p1.second = finy;
            } else if(s[i] == 'R') {
                finx++;
                p1.first = finx;
                p1.second = finy;
            } else if(s[i] == 'U') {
                finy++;
                p1.first = finx;
                p1.second = finy;
            } else if(s[i] == 'D') {
                finy--;
                p1.first = finx;
                p1.second = finy;
            }
            m[p1].push_back(i + 2);
            if(m[p1].size() >= 2) {
                st.insert(p1);
            }
            // if(i - m[p1] < mini) {
            //     mini = (i - m[p1]);
            //     l = m[p1] + 1;
            //     r = i + 1;
            // }
            // m[p1] = i;
        }
        set<pair<int, int>>::iterator it = st.begin();
        while(it != st.end()) {
            vector<int> temp = m[*it];
            for(int i=1;i<temp.size();i++) {
                if(temp[i] - temp[i - 1] < mini) {
                    mini = temp[i] - temp[i - 1];
                    l = temp[i - 1];
                    r = temp[i] - 1;
                }
            }
            it++;
        }
        if(l == -1) {
            cout << -1 << endl;
        } else {
            cout << l << " " << r << endl;
        }
    }
}