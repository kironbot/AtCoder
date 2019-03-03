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
    int L;
    cin >> L;
    int N = 0;
    int pow = 1;
    while(pow <= L) pow *= 2, N++;
    int M = (N-1)*2 + __builtin_popcount(L) - 1;

    cout << N << " " << M << endl;
    rep(i, 0, N-1) {
        cout << i+1 << " " << i+2 << " " << 0 << endl;
        cout << i+1 << " " << i+2 << " " << (1<<i) << endl;
    }
    int cur = 1<<(N-1);
    for(int i = N-2; i >= 0; i--) {
        if (L & (1<<i)) {
            cout << i+1 << " " << N << " " << cur << endl;
            cur += (1<<i);
        }
    }
}
