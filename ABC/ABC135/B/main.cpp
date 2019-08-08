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
    ll n;
    cin >> n;
    vector<ll> p(n);
    rep(i, 0, n) {
        ll x;
        cin >> x;
        x--;
        p[i] = x;
    }

    rep(i, 0, n) rep(j, i, n) {
        bool ok = true;
        rep(k, 0, n) {
            ll tmp;
            if(k == i) tmp = p[j];
            else if(k == j) tmp = p[i];
            else tmp = p[k];
            if(tmp != k) ok = false;
        }
        if(ok) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}

