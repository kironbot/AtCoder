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
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x << ": " << x << endl;
#else
    #define debug(x)
#endif

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    string A, B;
    cin >> A;
    B = A;
    reverse(B.begin(), B.end());
    ll n = A.size();

    ll cnt = 0, mark = -1;
    rep(i, (n+1)/2) if(A[i] != B[i]) cnt++, mark = i;

    if(n == 1) cout << 0 << endl;
    else if(cnt == 0) cout << 25 * (n - n % 2) << endl;
    else if(cnt == 1) cout << 25 * n - 2 << endl;
    else  cout << 25 * n << endl;

}
