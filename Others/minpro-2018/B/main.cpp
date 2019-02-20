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
    ll x, k;
    cin >> x >> k;
    ll unit = (ll)pow(10, k);
    for (ll i = unit; i < 1LL<<60 ;i += unit) {
        if (i >= x + 1) {
            cout << i << endl;
            return 0;
        }
    }
}
