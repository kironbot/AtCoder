#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
#define rep(i, a, n) for (ll i = (a); i < (n); i++)
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

const int MAX = 101000;      // 素数判定する最大の数
bool IsPrime[MAX];
vector<int> Era(int n = MAX) {
    vector<int> res;
    IsPrime[0] = false; IsPrime[1] = false;
    for (int i = 2; i < n; ++i) IsPrime[i] = true;
    for (int i = 2; i < n; ++i) {
        if (IsPrime[i]) {
            res.push_back(i);
            for (int j = i*2; j < n; j += i) IsPrime[j] = false;
        }
    }
    return res;
}

int main() {
    auto primes = Era();
    vector<ll> cnt(101000, 0);
    cnt[3] = 1;
    rep(i, 4, 101000) {
        if (i % 2 == 1 && IsPrime[i] && IsPrime[(i+1)/2]) cnt[i] = cnt[i-1] + 1;
        else cnt[i] = cnt[i-1];
    }

    ll q;
    cin >> q;
    rep(i, 0, q) {
        ll l, r;
        cin >> l >> r;
        cout << cnt[r] - cnt[l-1] << endl;
    }
}
