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
    rep(i, 1, 3501) rep(j, 1, 3501) {
        if (4*i*j-n*i-n*j <= 0) continue;
        if (n*i*j % (4*i*j-n*i-n*j) != 0) continue;
        ll k = n*i*j / (4*i*j-n*i-n*j);
        cout << i << " " << j << " " << k << endl;
        return 0;
    }
}