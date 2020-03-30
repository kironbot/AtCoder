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

int main() {
    ll M, N, K;
    cin >> M >> N >> K;
    vvll sj(M+1, vll(N+1, 0));
    vvll so(M+1, vll(N+1, 0));
    vvll si(M+1, vll(N+1, 0));

    rep(i, M) rep(j, N) {
        char c;
        cin >> c;
        sj[i+1][j+1] = sj[i][j+1] + sj[i+1][j] - sj[i][j];
        so[i+1][j+1] = so[i][j+1] + so[i+1][j] - so[i][j];
        si[i+1][j+1] = si[i][j+1] + si[i+1][j] - si[i][j];
        if(c == 'J') sj[i+1][j+1]++;
        if(c == 'O') so[i+1][j+1]++;
        if(c == 'I') si[i+1][j+1]++;
    }

    rep(k, K) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        a--, b--, c--, d--;
        ll ansj = sj[c+1][d+1] - sj[c+1][b] - sj[a][d+1] + sj[a][b];
        ll anso = so[c+1][d+1] - so[c+1][b] - so[a][d+1] + so[a][b];
        ll ansi = si[c+1][d+1] - si[c+1][b] - si[a][d+1] + si[a][b];
        cout << ansj << " " << anso << " " << ansi << endl;
    }

}
