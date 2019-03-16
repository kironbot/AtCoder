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
    ll n, c;
    cin >> n >> c;
    deque<ll> dq(n);
    rep(i, 0, n) cin >> dq[i];
    sort(dq.begin(), dq.end());

    ll ans = 0;
    while(!dq.empty()) {
        ll tmp = dq.back();
        dq.pop_back();
        if (!dq.empty() && c-tmp-1 >= dq.front()) dq.pop_front();
        ans++;
    }
    cout << ans << endl;
}