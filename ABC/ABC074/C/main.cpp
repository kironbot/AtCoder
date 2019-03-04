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
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    ll ans_total = 100 * a, ans_sugar = 0;
    double dns = 0;
    for(int ia = 0; ia * a <= f; ia++) {
        for(int ib = 0; ib * b <= f - ia * a; ib++) {
            ll water = 100 * (ia * a + ib * b);
            ll maxsugar = min(f - water, e * (water / 100));
            for(int ic = 0; ic * c <= maxsugar; ic++){
                for(int id = 0; id * d <= maxsugar - ic * c; id++) {
                    if (ia == 0 && ib == 0) continue;
                    ll sugar = ic * c + id * d;
                    ll total = water + sugar;
                    if (total > f) continue;
                    if (sugar  * (100 + e) > e * total) continue;

                    double tmp = ((double)sugar/(double)total);
                    if (tmp > dns) {
                        dns = tmp;
                        ans_total = total;
                        ans_sugar = sugar;
                    }
                }
            }
        }
    }
    cout << ans_total << " " << ans_sugar << endl;
}
