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
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    int dx = tx-sx, dy = ty - sy;    
    cout << string(dy, 'U') << string(dx, 'R');
    cout << string(dy, 'D') << string(dx, 'L');
    cout << 'L' << string(dy+1, 'U') << string(dx+1, 'R') << 'D';
    cout << 'R' << string(dy+1, 'D') << string(dx+1, 'L') << 'U';
    cout << endl;
}
