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
    ll K, N;
    cin >> K >> N;
    vll A(N+1);
    A[0] = 0;
    ll total = 0, maxa = 0;
    rep(i, N) {
        cin >> A[i+1];
        total += A[i+1] - A[i];
        chmax(maxa, A[i+1] - A[i]);
    }
    chmax(maxa, A[1] + K - A[N]);
    cout << K - maxa << endl;
}
