#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vc = vector<char>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using stkll = vector<pll>;
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
#define rep(i, n) for (ll i = 0; i < (n); i++)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x << ": " << x << endl;
#else
    #define debug(x)
#endif

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll n; cin >> n;
    vector<long double> x(n), y(n);
    rep(i,n) cin >> x[i] >> y[i];

    const long double eps = 1e-10;
    long double pi = acos(-1.0);
    ll cnt1 = 0, cnt2 = 0, cnt3 = 0;
    rep(i, n) {
        vector<long double> angle;
        rep(j, n) if(i != j) angle.push_back(atan2(y[j]-y[i], x[j]-x[i]));

        // [-PI, PI] が扱いずらいため[PI, 3*PI]に直す
        rep(j, n-1) angle.push_back(angle[j] + 2*pi);

        sort(angle.begin(), angle.end());
        rep(j, n-1) {
            cnt2 += upper_bound(angle.begin(), angle.end(), angle[j] + pi/2.0 + eps)
                    - lower_bound(angle.begin(), angle.end(), angle[j] + pi/2.0 - eps);
            cnt3 += lower_bound(angle.begin(), angle.end(), angle[j] + pi - eps)
                    - upper_bound(angle.begin(), angle.end(), angle[j] + pi/2.0 + eps);
        }
    }
    cnt1 = n*(n-1)*(n-2)/6 - cnt2 - cnt3;
    cout << cnt1 << " " << cnt2 << " " << cnt3 << endl;
}
