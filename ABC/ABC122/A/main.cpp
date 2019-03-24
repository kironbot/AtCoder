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
    char b;
    cin >> b;
    if (b == 'A') cout << 'T' << endl;
    if (b == 'T') cout << 'A' << endl;
    if (b == 'C') cout << 'G' << endl;
    if (b == 'G') cout << 'C' << endl;
}
