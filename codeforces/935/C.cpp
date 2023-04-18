#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
#define setpres cout << fixed << setprecision(10)
#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e18;

#ifdef DEBUG
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }

double sq_dist(double x1, double y1, double x2, double y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
bool outside(double R, double x1, double y1, double x2, double y2) {
    return sq_dist(x1, y1, x2, y2) >= R * R;
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        setpres;
        double R, x1, y1, x2, y2;
        cin >> R >> x1 >> y1 >> x2 >> y2;
        if(outside(R, x1, y1, x2, y2)) cout << x1 << " " << y1 << " " << R << endl;
        else {
            dbg(y2 - y1);
            dbg(x2 - x1);
            double m = (y2 - y1) / (x2 - x1);
            double c = y2 - m * x2;
            dbg(m, c);

            // assert(c == 0);

            c += m * (x1) - y1;
            dbg(c);

            // y = mx + c
            // x2 + y2 = R2
            // x2 + m2x2 + c2 + 2mxc = R2
            // x2(1 + m2) + 2mxc + c2 - R2 = 0
            // b2 - 4ac
            double b = (2 * m * c) / (1 + m * m);
            double b2 = b * b;
            double d2 = b2 - 4 * (c * c - R * R) / (1 + m * m);
            dbg(d2);
            // assert(d2 >= 0);
            double d = sqrt(d2);
            dbg(d);
            double xx1 = (-b + d) / 2;
            double xx2 = (-b - d) / 2;
            double yy1 = m * xx1 + c;
            double yy2 = m * xx2 + c;
            if(x1 == x2) {
                xx1 = xx2 = 0;
                yy1 = R;
                yy2 = -R;
            }
            dbg(xx1, xx2, yy1, yy2);
            x2 -= x1;
            y2 -= y1;
            dbg(x2, y2);

            dbg(x2, y2, xx1, yy1);
            double dl = sq_dist(x2, y2, xx1, yy1);
            double dr = sq_dist(x2, y2, xx2, yy2);
            dbg(dl, dr);

            if(dr > dl) {
                swap(dr, dl);
                swap(xx1, xx2);
                swap(yy1, yy2);
            }
            dl = sqrt(dl);

            double rad = dl / 2;
            dbg(dl, rad);

            double xans = x2 + (xx1 - x2) / 2;
            double yans = y2 + (yy1 - y2) / 2;
            dbg(xans, yans);

            cout << xans + x1 << " " << yans + y1 << " " << rad << endl;
        }
    }
}