#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
#include <deque>
#include <cmath>
#include <map>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

ll N, A, B, C;
vector<ll> L;

ll rec(ll used, ll a, ll b, ll c) {
    if (used == N) {
        if (a < 1 || b < 1 || c < 1) return 1LL<<60;
        else return abs(a-A) + abs(b-B) + abs(c-C);
    }

    ll res = rec(used+1, a, b, c);
    chmin(res, rec(used+1, a+L[used], b, c) + (a > 0 ? 10 : 0));
    chmin(res, rec(used+1, a, b+L[used], c) + (b > 0 ? 10 : 0));
    chmin(res, rec(used+1, a, b, c+L[used]) + (c > 0 ? 10 : 0));

    return res;
}

int main() {
    cin >> N >> A >> B >> C;
    L.resize(N);
    rep(i, N) cin >> L[i];
    cout << rec(0, 0, 0, 0) << endl;
}
