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
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x << ": " << x << endl;
#else
    #define debug(x)
#endif

int main() {
    cin.tie(0);ios::sync_with_stdio(false);cout << fixed << setprecision(20);

    ll N, M, K;
    cin >> N >> M >> K;
    
    vll A(N), B(M), SA(N+1, 0), SB(M+1, 0);
    rep(i,N) {
        cin >> A[i];
        SA[i+1] = SA[i] + A[i];
    }
    rep(i,M) {
        cin >> B[i];
        SB[i+1] = SB[i] + B[i];
    }

    ll ans = 0;
    rep(i, N+1) {
        if(SA[i] > K) break;
        ll tmp = i - 1 + (lower_bound(SB.begin(), SB.end(), K-SA[i]+1) - SB.begin());
        chmax(ans, tmp);
    }
    cout << ans << endl;
}
