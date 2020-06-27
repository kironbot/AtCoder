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

    ll N;
    cin >> N;
    vll A(N);
    rep(i,N) cin >> A[i];
    vll cnt(110000, 0);
    rep(i,N) cnt[A[i]]++;

    ll ans = 0;
    rep(i,N) ans += A[i];

    ll Q;
    cin >> Q;
    rep(_, Q) {
        ll b, c;
        cin >> b >> c;
        cnt[c] += cnt[b];
        ans -= b * cnt[b];
        ans += c * cnt[b];
        cnt[b] = 0;
        cout << ans << endl;
    }
}