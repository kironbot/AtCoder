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
#include <numeric>
using namespace std;
typedef long long ll;

ll gcd(ll m, ll n) {
    if (m < n) gcd(n, m);
    ll r;
    while (r = m % n) {
        m = n;
        n = r;
    }
    return n;
}

int main() {
    ll n, x;
    cin >> n >> x;
    ll ans;
    for(ll i=0; i<n; i++) {
        ll tmp;
        cin >> tmp;
        if(i==0) ans = abs(tmp - x);
        else ans = gcd(ans, abs(tmp - x));
    }
    cout << ans << endl;
}
