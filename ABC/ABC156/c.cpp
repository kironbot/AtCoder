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
    ll N;
    cin >> N;
    ll avg = 0;
    vll x(N);
    rep(i, N) {
        cin >> x[i];
        avg += x[i];
    }
    avg /= N;

    ll ans = INF;
    for(int i = -1; i <= 1; i++) {
        ll m = avg + i;
        ll tmp = 0;
        rep(i, N) tmp += pow(x[i] - m, 2);
        chmin(ans, tmp);
    }
    cout << ans << endl;
}
