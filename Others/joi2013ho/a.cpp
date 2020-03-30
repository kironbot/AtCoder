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

int main() {
    ll n, a, ans = 0;
    cin >> n;
    vll da;
    da.emplace_back(0);
    cin >> a;

    // 数字が連続する箇所を記録する
    for(ll i = 1; i < n; i++) {
        ll b;
        cin >> b;
        if(a==b) da.emplace_back(i);
        a = b;
    }
    da.emplace_back(n);

    // da.size() <= 3 の時、1点変えればすべて交互にできる
    if(da.size() <= 3) ans = n;
    else {
        rep(i, da.size() - 3) chmax(ans, da[i+3] - da[i]);
    }
    cout << ans << endl;
}