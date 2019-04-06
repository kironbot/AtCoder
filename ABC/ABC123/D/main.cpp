#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
#define rep(i, a, n) for (ll i = (a); i < (n); i++)
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main() {
    ll x, y, z, k;
    cin >> x >> y >> z >> k;
    vector<ll> va(x), vb(y), vc(z);
    rep(i, 0, x) cin >> va[i];
    rep(i, 0, y) cin >> vb[i];
    rep(i, 0, z) cin >> vc[i];

    vector<ll> sumab;
    rep(i, 0, x) rep(j, 0, y) sumab.emplace_back(va[i]+vb[j]);
    sort(sumab.begin(), sumab.end(), greater<ll>());

    vector<ll> ans;
    rep(i, 0, min(k, (ll)sumab.size())) rep(j, 0, z) ans.emplace_back(sumab[i]+vc[j]);
    sort(ans.begin(), ans.end(), greater<ll>());
    rep(i, 0, k) cout << ans[i] << endl;
}
