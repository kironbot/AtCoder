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
    vector<ll> p(n), q(n), v(n);
    rep(i, 0, n) v[i] = i+1;
    rep(i, 0, n) cin >> p[i];
    rep(i, 0, n) cin >> q[i];

    ll cnta=0, cntb=0, cnt=0;

    while(true){
        if(p == v) cnta = cnt;
        if(q == v) cntb = cnt;
        cnt++;
        if(!next_permutation(v.begin(), v.end())) break;
    }

    cout << abs(cnta - cntb) << endl;
}
