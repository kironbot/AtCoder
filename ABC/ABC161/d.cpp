#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vc = vector<char>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using stkll = vector<pll>;
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main() {
    ll K;
    cin >> K;

    queue<ll> que;
    rep(i, 9) que.push(i+1);

    ll cnt = 0;
    while(!que.empty()) {
        ll v = que.front();
        que.pop();
        cnt++;
        if(cnt == K) {
            cout << v << endl;
            return 0;
        }

        ll x = v % 10;
        for(int i = -1; i <= 1; i++) {
            if(x == 0 && i == -1) continue;
            if(x == 9 && i == 1) continue;
            que.push(10 * v + x + i);
        }
    }
}
