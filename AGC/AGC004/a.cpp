#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
#include <deque>
#include <cmath>
#include <map>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    ll mins = 1LL<<60;
    chmin(mins, a*b);
    chmin(mins, a*c);
    chmin(mins, c*b);
    if (a % 2 == 0 || b % 2 == 0 || c % 2 == 0) cout << 0 << endl;
    else cout << mins << endl;
}
