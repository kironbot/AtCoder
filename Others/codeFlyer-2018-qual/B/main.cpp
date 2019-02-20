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
    ll a, b, n;
    string x;
    cin >> a >> b >> n >> x;
    ll resta = a, restb = b;
    rep(i, n) {
        if(x[i] == 'S') {
            if(resta > 0) resta--;
        } else if (x[i] == 'C') {
            if(restb > 0) restb--;
        } else {
            if (resta >= restb && resta > 0) resta--;
            else if (restb > 0) restb--;
        }
    }
    cout << resta << endl;
    cout << restb << endl;
}
