#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m, a[50], b[50];
        long long sumA = 0, sumB = 0;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            cin >> a[i], sumA += a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i], sumB += b[i];
        if (sumA > sumB) cout << "Tsondu\n";
        if (sumA < sumB) cout << "Tenzing\n";
        if (sumA == sumB) cout << "Draw\n";
    }
}