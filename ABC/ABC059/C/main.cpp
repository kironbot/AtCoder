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
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];

    ll sum1 = 0, sum2 = 0, tmp1 = 0, tmp2 = 0;
    rep(i, 0, n) {
        sum1 += a[i], sum2 += a[i];
        if (i % 2 == 0) {
            if (sum1 <= 0) tmp1 += abs(sum1) + 1, sum1 = 1;
            if (sum2 >= 0) tmp2 += abs(sum2) + 1, sum2 = -1;
        } else {
            if (sum1 >= 0) tmp1 += abs(sum1) + 1, sum1 = -1;
            if (sum2 <= 0) tmp2 += abs(sum2) + 1, sum2 = 1;
        }
    }
    cout << min(tmp1, tmp2) << endl;
}