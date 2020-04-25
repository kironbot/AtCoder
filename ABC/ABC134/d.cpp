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
    ll N; cin >> N;
    vll a(N+1);
    rep(i, N) cin >> a[i+1];
    vll ans(N+1, 0);
    ll cnt = 0;
    for(ll i = N; i >= 1; i--) {
        ll sum = 0;
        for(ll k = N/i; k > 1; k--) sum += ans[i * k];

        if(sum % 2 == a[i]) ans[i] = 0;
        else ans[i] = 1, cnt++;
    }

    if(cnt == 0) {
        cout << 0 << endl;
        return 0;
    }

    cout << cnt << endl;
    rep(i, N) if(ans[i+1] == 1) cout << i+1 << " ";
    cout << endl;
}
