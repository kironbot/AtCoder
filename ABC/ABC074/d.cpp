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
    vvll A(N, vll(N));
    rep(i, N) rep(j, N) cin >> A[i][j];

    bool ok = true;
    rep(i, N) rep(j, N) rep(k, N) {
        if(i == k || j == k) continue;
        if(A[i][j] > A[i][k] + A[k][j]) ok = false;
    }
    if(!ok) {
        cout << -1 << endl;
        return 0;
    }

    vvll B(N, vll(N));
    rep(i, N) rep(j, N) B[i][j] = A[i][j];
    rep(i, N) rep(j, N) rep(k, N) {
        if(i == k || j == k) continue;
        if(A[i][j] == A[i][k] + A[k][j]) B[i][j] = 0;
    }

    ll ans = 0;
    rep(i, N) rep(j, N) {
        if(i >= j) continue;
        ans += B[i][j];
    }
    cout << ans << endl;
}
