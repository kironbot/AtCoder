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

ll N, M, Q;
vll a, b, c, d;
ll ans = 0;

void dfs(vll A) {
    if (A.size() == N+1) {
        ll now = 0;
        rep(i, Q) if(A[b[i]] - A[a[i]] == c[i]) now += d[i];
        chmax(ans, now);
        return;
    }

    A.push_back(A.back());
    while(A.back() <= M) {
        dfs(A);
        A.back()++;
    }
}


int main() {
    cin >> N >> M >> Q;
    a = b = c = d = vll(Q);
    rep(i, Q) cin >> a[i] >> b[i] >> c[i] >> d[i];
    dfs(vll(1, 1));
    cout << ans << endl;
}

