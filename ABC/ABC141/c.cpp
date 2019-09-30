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
    ll n, k, q;
    cin >> n >> k >> q;
    ll bar = max(0LL, q-k+1);
    map<ll, ll> cnt;
    rep(i, 0, q) {
        ll a;
        cin >> a;
        a--;
        cnt[a]++;
    }
    rep(i, 0, n) {
        if (cnt[i] >= bar) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
