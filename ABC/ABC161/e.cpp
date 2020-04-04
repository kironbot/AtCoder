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
    ll N, K, C;
    cin >> N >> K >> C;
    string S;
    cin >> S;

    vll L(K+1), R(K+1);

    ll rest = 0, cntk = 0;
    rep(i, N) {
        if(cntk >= K) break;
        if(S[i] == 'o' && rest <= 0) cntk++, L[cntk] = i, rest = C;
        else rest--;
    }

    rest = 0, cntk = 0;
    for(ll i = N-1; i >= 0; i--) {
        if(cntk >= K) break;
        if(S[i] == 'o' && rest <= 0) cntk++, R[K+1-cntk] = i, rest = C;
        else rest--;
    }

    vll ans;
    for(ll i = 1; i <= K; i++) {
        if(L[i] == R[i]) ans.push_back(L[i]+1);
    }

    for(auto x : ans) cout << x << endl;
}
