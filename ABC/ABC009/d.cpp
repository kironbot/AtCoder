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

using mat = vector<vector<ll>>;
ll K, M;

mat mul(mat &A, mat &B) {
    mat C(A.size(), vector<ll>(B[0].size()));
    rep(i, A.size()) rep(k, B.size()) rep(j, B[0].size()) {
        C[i][j] = C[i][j] ^ (A[i][k] & B[k][j]);
    }
    return C;
}

mat pow(mat A, ll n) {
    mat B(A.size(), vector<ll>(A.size()));
    rep(i, A.size()) B[i][i] = (1LL<<32)-1;
    while(n > 0) {
        if(n % 2 == 1) B = mul(B, A);
        A = mul(A, A);
        n /= 2;
    }
    return B;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    cin >> K >> M;
    vll A(K), C(K);
    rep(i, K) cin >> A[i];
    rep(i, K) cin >> C[i];

    mat B(K, vll(K));
    rep(i, K) B[0][i] = C[i];
    rep(i, K-1) B[i+1][i] = (1LL<<32)-1;

    if(M <= K) {
        cout << A[M-1] << endl;
        return 0;
    }

    B = pow(B, M-K);

    ll ans = 0;
    rep(i, K) ans ^= B[0][i] & A[K-1-i];
    cout << ans << endl;
}
