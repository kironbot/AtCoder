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
    ll q, h, s, d, n;
    cin >> q >> h >> s >> d >> n;
    ll m1=s, m2=d;
    chmin(m1, 4*q);
    chmin(m1, 2*h);
    chmin(m2, 2*s);
    if (2*m1 <= m2) cout << n * m1 << endl;
    else cout << (n/2)*m2 + (n%2)*m1 << endl;
}