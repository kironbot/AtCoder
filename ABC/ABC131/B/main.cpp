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
    ll n, l;
    cin >> n >> l;

    ll sum = 0;
    rep(i, 1, n+1) sum += l+i-1;    
    
    ll ans = 0, cnt = INF;
    rep(i, 1, n+1) {
        if (abs(cnt) > abs(l+i-1)) {
            ans = (l+i-1);
            cnt = abs(l+i-1);
        }
    }
    cout << sum - ans << endl;
}
