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
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    vector<ll> left(n), right(n);
    left[0] = a[0];
    right[n-1] = a[n-1];
    rep(i, 1, n) {
        left[i] = max(left[i-1], a[i]);
        right[n-1-i] = max(right[n-i], a[n-1-i]);
    }
    rep(i, 0, n) {
        if (i-1 < 0) cout << right[1] << endl;
        else if (i+1 > n-1) cout << left[n-2] << endl;
        else cout << max(left[i-1], right[i+1]) << endl;
    }
}