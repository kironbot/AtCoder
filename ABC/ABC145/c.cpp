#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main() {
    ll N;
    cin >> N;
    vector<ll> x(N), y(N), vec(N);
    rep(i, N) cin >> x[i] >> y[i];
    rep(i, N) vec[i] = i;

    double ans = 0;
    do {
        rep(i, N-1) ans += hypot(x[vec[i]]-x[vec[i+1]], y[vec[i]]-y[vec[i+1]]);
    } while(next_permutation(vec.begin(), vec.end()));

    rep(i, N) ans /= i+1;

    cout.precision(10);
    cout << ans << endl;
}
