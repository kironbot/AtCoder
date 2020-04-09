#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vc = vector<char>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main() {
    ll N, K;
    cin >> N >> K;
    vector<double> sum(N+1, 0.0);
    rep(i, N) {
        double p;
        cin >> p;
        sum[i+1] += sum[i] + (p + 1.0) / 2.0;
    }

    double ans = 0;
    rep(i, N-K+1) chmax(ans, sum[i+K] - sum[i]);
    cout.precision(20);
    cout << ans << endl;
}
