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
    ll n, m;
    cin >> n >> m;
    vll s(n, 0);
    rep(i, n-1) {
        ll ts;
        cin >> ts;
        s[i+1] = s[i] + ts;
    }

    ll ans = 0, now = 0;
    rep(i, m) {
        ll a;
        cin >> a;
        ll next = now + a;
        ans += abs(s[next] - s[now]);
        now = next;
    }
    cout << ans % 100000 << endl;
}
