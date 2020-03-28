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

ll dig(ll n) {
    ll ans = 0;
    while(n) {
        ans++;
        n /= 10;
    }
    return ans;
}


int main() {
    ll A, B, X;
    cin >> A >> B >> X;

    ll right = 1e9 + 1, left = 0;
    while(right - left > 1) {
        ll mid = (left + right) / 2;
        if(A * mid + B * dig(mid) <= X) left = mid;
        else right = mid;
    }
    cout << left << endl;
}
