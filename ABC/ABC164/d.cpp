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
    string S;
    cin >> S;
    vll cnt(3000, 0);
    cnt[0] = 1;
    ll num = 0;
    ll digit = 1;
    for(ll i = S.size()-1; i>=0; i--) {
        ll a = S[i] - '0';
        num += digit * a;
        num %= 2019;
        digit *= 10;
        digit %= 2019;
        cnt[num]++;
    }
    ll ans = 0;
    rep(i, 2019) if(cnt[i] >= 2) ans += cnt[i] * (cnt[i] - 1) / 2;
    cout << ans << endl;
}
