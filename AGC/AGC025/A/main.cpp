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

ll digsum(ll n) {
    ll sum = 0;
    while(n > 0){
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    ll n;
    cin >> n;
    ll ans = 1LL<<60;
    for (ll i = 1; i <= n-1; i++) {
        ll tmp = digsum(i) + digsum(n-i);
        chmin(ans, tmp);
    }
    cout << ans << endl;
}
