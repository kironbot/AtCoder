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
    ll a, b, k;
    cin >> a >> b >> k;

    while(k > 0) {
        if (a % 2 == 1) a--;
        b += a/2;
        a /= 2;
        k--;
        if (k > 0) {
            if (b % 2 == 1) b--;
            a += b/2;
            b /= 2;
            k--;
        }
    }
    cout << a << " " << b << endl;
}