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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    ll ans = 0, sum = 0, right = 0;
    for(ll left = 0; left < n; left++) {
        while(right < n && sum + a[right] < k) {
            sum += a[right];
            right++;
        }
        ans += (right - left);
        if (right == left) right++;
        else sum -= a[left];
    }
    cout << n*(n+1)/2 - ans << endl;
}
