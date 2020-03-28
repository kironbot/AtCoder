#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vc = vector<char>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
const ll INF = 1LL << 30;
const ll MOD = 1e9 + 7;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main() {
    ll N, X, Y;
    cin >> N >> X >> Y;
    X--, Y--;
    vector<vector<ll>> d(N, vector<ll>(N, -1));
    rep(i, N-1) d[i][i+1] = 1;
    d[X][Y] = 1;

    rep(i, N) rep(j, N) {
        if(i >= j) continue;
        if(j <= X || Y <= i) d[i][j] = j -i;
        else if (X <= i && j <= Y) d[i][j] = min(j - i, 1 + Y - j + i - X);
        else if (i <= X && Y <= j) d[i][j] = X - i + 1 + j - Y;
        else if (i <= X && X <= j && j <= Y) d[i][j] = X - i + min(j - X, 1 + Y - j);
        else if (X <= i && i <= Y && Y <= j) d[i][j] = min(Y - i, i - X + 1) + j - Y;
    }

    vector<ll> ans(N-1, 0);
    rep(i, N) rep(j, N) {
        if(i >= j) continue;
        ans[d[i][j] - 1]++;
    }

    rep(i, N-1) cout << ans[i] << endl;
}
