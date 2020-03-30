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
    ll n;
    cin >> n;
    vll cnt(11000000, 0);
    rep(i, n) {
        ll a, b;
        cin >> a >> b;
        cnt[a]++;
        cnt[b+1]--;
    }
    rep(i, 11000000) if(0 < i) cnt[i] += cnt[i-1];

    ll ans = 0;
    rep(i, 11000000) chmax(ans, cnt[i]);
    cout << ans << endl;
}
