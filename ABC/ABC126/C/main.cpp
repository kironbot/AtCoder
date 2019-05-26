#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
#define rep(i, a, n) for (ll i = (a); i < (n); i++)
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main() {
    double n, k;
    cin >> n >> k;

    double ans = 0;
    for (ll in = 1; in <= n; in++) {
        double tmp = 1.0 / n;
        if (in < k) {
            for (ll i = 1; i < log2(k/in) + 1; i++) tmp /= 2;
        }
        ans += tmp;
    }

    cout.precision(20);
    cout << ans << endl;
}
