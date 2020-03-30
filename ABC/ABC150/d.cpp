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
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

ll count(ll n) {
    ll ans = 0;
    while(n > 0 && n % 2 == 0) {
        ans++;
        n /= 2;
    }
    return ans;
}


int main() {
    ll N, M;
    cin >> N >> M;
    ll lcm = 1, cnt;
    bool ok = true;
    rep(i, N) {
        ll a;
        cin >> a;

        if(i == 0) cnt = count(a);
        else if(cnt != count(a)) ok = false;

        a /= 2;
        lcm = lcm * a / __gcd(lcm, a);

        if(lcm > M) ok = false;
    }

    if(!ok) cout << 0 << endl;
    else cout << (M / lcm + 1) / 2 << endl;
}