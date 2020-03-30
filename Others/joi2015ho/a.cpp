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
    ll N, M;
    cin >> N >> M;

    vll P(M);
    rep(i, M) cin >> P[i];

    vll A(N-1), B(N-1), C(N-1);
    rep(i, N-1) cin >> A[i] >> B[i] >> C[i];

    vll s(N+1, 0);
    rep(i, M-1) {
        if(P[i] < P[i+1]) s[P[i]]++, s[P[i+1]]--;
        else s[P[i+1]]++, s[P[i]]--;
    }
    rep(i, N) if(i > 0) s[i+1] += s[i];

    ll ans = 0;
    rep(i, N) {
        if(s[i+1] * A[i] <= s[i+1] * B[i] + C[i]) ans += s[i+1] * A[i];
        else ans += s[i+1] * B[i] + C[i];
    }
    cout << ans << endl;
}
